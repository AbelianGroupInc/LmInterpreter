using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LM1 : LM
    {
        const int REGISTER_NUMBER = 16;
        int[] cpuMemory;

        #region Commands defines
        const int
            CMD_RM_INPUT = 6,
            CMD_RM_OUTPUT = 7,
            CMD_RM_UNSIGNED_INPUT = 22,
            CMD_RM_UNSIGNED_OUTPUT = 23,
            CMD_RM_ADD = 1,
            CMD_RM_SUBSRACT = 2,
            CMD_RM_MULTIPLICATION = 3,
            CMD_RM_DIVISION = 4,
            CMD_RM_UNSIGNED_MULTIPLICATION = 19,
            CMD_RM_UNSIGNED_DIVISION = 20,
            CMD_RM_ASSIGMENT_1 = 0,
            CMD_RM_ASSIGMENT_2 = 16,
            CMD_GO_TO = 128,
            CMD_LESS = 131,
            CMD_GREATER = 133,
            CMD_LESS_OR_EQUAL = 134,
            CMD_GREATER_OR_EQUAL = 132,
            CMD_EQUAL = 129,
            CMD_NOT_EQUAL = 130,
            CMD_UNSIGNED_LESS = 147,
            CMD_UNSIGNED_GREATER = 149,
            CMD_UNSIGNED_LESS_OR_EQUAL = 148,
            CMD_UNSIGNED_GREATER_OR_EQUAL = 150,
            CMD_RM_COMPARISON = 05,
            COMMAND_IS_LONG = 100;
        const int
            CMD_RR_STOP = 153,
            CMD_RR_ASSIGMENT = 32,
            CMD_RR_ADD = 33,
            CMD_RR_SUBSTRACT = 34,
            CMD_RR_MULTIPLICATION = 35,
            CMD_RR_UNSIGNED_MULTIPLICATION = 51,
            CMD_RR_DIVISION = 36,
            CMD_RR_UNSIGNED_DIVISION = 52,
            CMD_RR_COMPARISON = 37,
            COMMAND_IS_NOT_LONG = 200,
            COMMAND_SECOND_PART = 300;
        #endregion

        public LM1()
            : base()
        {
            cpuMemory = new int[REGISTER_NUMBER];
            for (int i = 0; i < REGISTER_NUMBER; i++)
                cpuMemory[i] = Int32.MaxValue;
        }

        #region Main methods

        #region InitialiseCommand
        protected override void InitialiseCommand(List<int> command)
        {
            try
            {
                if (CommandIsLong(command[1]))
                    InitialiseLongCommand(command);
                else
                    InitialiseShortCommand(command);
            }
            catch (Exception exp)
            {
                throw new System.Exception(exp.Message + ' ' +
                    TextFormat.addZeros(Convert.ToString(command[0], 16), 4));
            }
        }
        private void InitialiseLongCommand(List<int> command)
        {
            CheckLongCommandFormat(command);
            CheckLongCommandAddress(command[0]);

            if (currentAddress == UNINITIALIZED_ADDRESS)
                currentAddress = command[0];

            ramMemory.SetCell(command[0],
                new LM1LongCommand(command[1], command[2], command[3], command[4]));
            ramMemory.SetCell(command[0] + 1,
                new LM1LongCommand(COMMAND_SECOND_PART, command[2], command[3], command[4]));

            /*if (this->ram_memory.get(cur_command_address)->get_value() == CMD_RR_STOP)
                end = true;*/
        }
        private void InitialiseShortCommand(List<int> command)
        {
            CheckShortCommandFormat(command);
            CheckLongCommandAddress(command[0]);

            ramMemory.SetCell(command[0],
                new LM1ShortCommand(command[1], command[2], command[3]));

            /*if (this->ram_memory.get(cur_command_address)->get_value() == CMD_RR_STOP)
                end = true;*/
        }
        private void CheckLongCommandFormat(List<int> command)
        {
            if (command.Count < 5)
                throw new Exception("Too few fields");
            else if (command.Count > 5)
                throw new Exception("Too many fields");
        }
        private void CheckShortCommandFormat(List<int> command)
        {
            if (command.Count < 4)
                throw new Exception("Too few fields");
            else if (command.Count > 4)
                throw new Exception("Too many fields");
        }
        private void CheckLongCommandAddress(int commandAddress)
        {
            if ((commandAddress + 1) > MAX_MEMORY_SIZE)
                throw new Exception("Memory bounds violation");

            if (!ramMemory.IsMemoryCellEmpty(commandAddress) ||
                !ramMemory.IsMemoryCellEmpty(commandAddress + 1))
                throw new Exception("Writing in ocuppied cell");
        }
        private void CheckShortCommandAddress(int commandAddress)
        {
            if (!ramMemory.IsMemoryCellEmpty(commandAddress))
                throw new Exception("Writing in ocuppied cell");
        }
        protected override void ClearMemory()
        {
            base.ClearMemory();

            for (int i = 0; i < cpuMemory.Length; i++)
                cpuMemory[i] = Int32.MaxValue;
        }
        public bool CommandIsLong(int commandNumber)
        {
            if (commandNumber == CMD_RM_INPUT ||
                commandNumber == CMD_RM_OUTPUT ||
                commandNumber == CMD_RM_UNSIGNED_INPUT ||
                commandNumber == CMD_RM_UNSIGNED_OUTPUT ||
                commandNumber == CMD_RM_ADD ||
                commandNumber == CMD_RM_SUBSRACT ||
                commandNumber == CMD_RM_MULTIPLICATION ||
                commandNumber == CMD_RM_DIVISION ||
                commandNumber == CMD_RM_UNSIGNED_MULTIPLICATION ||
                commandNumber == CMD_RM_UNSIGNED_DIVISION ||
                commandNumber == CMD_RM_ASSIGMENT_1 ||
                commandNumber == CMD_RM_ASSIGMENT_2 ||
                commandNumber == CMD_GO_TO ||
                commandNumber == CMD_LESS ||
                commandNumber == CMD_GREATER ||
                commandNumber == CMD_LESS_OR_EQUAL ||
                commandNumber == CMD_GREATER_OR_EQUAL ||
                commandNumber == CMD_EQUAL ||
                commandNumber == CMD_UNSIGNED_LESS ||
                commandNumber == CMD_UNSIGNED_GREATER ||
                commandNumber == CMD_UNSIGNED_LESS_OR_EQUAL ||
                commandNumber == CMD_UNSIGNED_GREATER_OR_EQUAL ||
                commandNumber == COMMAND_IS_LONG)
                return true;
            else
                return false;
        }
        #endregion

        protected override void MasterSwitch(RichTextBox textbox)
        {
            switch (GetCurrentCommandNumber())
            {
                case CMD_RM_INPUT:
                    LMCommands.InputMessage(textbox, GetName(GetAddressOperand(currentAddress, GetInOutOperand())));
                    inputFlag = true;
                    break;
                case CMD_RM_OUTPUT:
                    LM1Operations.PerformOutputOperation(this, LMCommands.Output, textbox);
                    break;

                case CMD_RM_UNSIGNED_INPUT:
                    LMCommands.InputMessage(textbox, GetName(GetAddressOperand(currentAddress, GetInOutOperand())));
                    uInputFlag = true;
                    break;
                case CMD_RM_UNSIGNED_OUTPUT:
                    LM1Operations.PerformOutputOperation(this, LMCommands.UnsignedOuput, textbox);
                    break;
                case CMD_RM_ADD:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.Add);
                    break;
                case CMD_RR_ADD:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.Add);
                    break;
                case CMD_RM_SUBSRACT:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.Substract);
                    break;
                case CMD_RR_SUBSTRACT:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.Substract);
                    break;
                case CMD_RM_MULTIPLICATION:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.Multiplication);
                    break;
                case CMD_RR_MULTIPLICATION:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.Multiplication);
                    break;
                case CMD_RM_DIVISION:
                    LM1Operations.PerformDivisionOperation(this, LMCommands.Division, LMCommands.Module);
                    break;
                case CMD_RR_DIVISION:
                    LM1Operations.PerformDivisionOperation(this, LMCommands.Division, LMCommands.Module);
                    break;
                case CMD_RM_UNSIGNED_MULTIPLICATION:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.UnsignedMultiplication);
                    break;
                case CMD_RR_UNSIGNED_MULTIPLICATION:
                    LM1Operations.PerformArithmeticOperation(this, LMCommands.UnsignedMultiplication);
                    break;
                case CMD_RR_UNSIGNED_DIVISION:
                    LM1Operations.PerformDivisionOperation(this, LMCommands.UnsignedDivision, LMCommands.UnsignedModule);
                    break;
                case CMD_RM_UNSIGNED_DIVISION:
                    LM1Operations.PerformDivisionOperation(this, LMCommands.UnsignedDivision, LMCommands.UnsignedModule);
                    break;
                case CMD_RM_ASSIGMENT_1:
                    LM1Operations.PerformRMRRAssignmentOperation(this);
                    break;
                case CMD_RM_ASSIGMENT_2:
                    LM1Operations.PerformFromRInMAssignmentOperation(this);
                    break;
                case CMD_RR_ASSIGMENT:
                    LM1Operations.PerformRMRRAssignmentOperation(this);
                    break;
                case CMD_RM_COMPARISON:
                    LM1Operations.PerformFlagDetermination(this);
                    break;
                case CMD_RR_COMPARISON:
                    LM1Operations.PerformFlagDetermination(this);
                    break;
                case CMD_LESS:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.LESS);
                    break;
                case CMD_GREATER:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.GREATER);
                    break;
                case CMD_LESS_OR_EQUAL:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.LESS_OR_EQUAL);
                    break;
                case CMD_GREATER_OR_EQUAL:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.GREATER_OR_EQUAL);
                    break;
                case CMD_EQUAL:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.EQUAL);
                    break;
                case CMD_NOT_EQUAL:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.N_EQUAL);
                    break;
                case CMD_UNSIGNED_LESS:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.INS_LESS);
                    break;
                case CMD_UNSIGNED_GREATER:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.INS_GREATER);
                    break;
                case CMD_UNSIGNED_LESS_OR_EQUAL:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.INS_LESS_OR_EQUAL);
                    break;
                case CMD_UNSIGNED_GREATER_OR_EQUAL:
                    LM1Operations.PerformComparisonOperation(this, LM1Operations.ComparisonFlag.INS_GREATER_OR_EQUAL);
                    break;
                case CMD_GO_TO:
                    LM1Operations.PerformGoToOperation(this);
                    break;
                case CMD_RR_STOP:
                    this.endFlag = true;
                    break;
                default:
                    break;
            }
        }

        #endregion

        #region Auxiliary methods
        public override List<string> GetVarInfo()
        {
            List<string> varInfo = base.GetVarInfo();
            for (int i = 0; i < cpuMemory.Length; i++)
                if (cpuMemory[i] != Int32.MaxValue)
                    varInfo.Add(String.Format("R{0} := {1}", i, cpuMemory[i]));

            return varInfo;
        }

        public override List<string> GetVarInfoInAdditionalCode()
        {
            List<string> varInfoInAdditionalCode = base.GetVarInfoInAdditionalCode();
            for (int i = 0; i < cpuMemory.Length; i++)
                if (cpuMemory[i] != Int32.MaxValue)
                    varInfoInAdditionalCode.Add(String.Format("R{0} := {1} ({2})", i, cpuMemory[i], TextFormat.additionalCode32(cpuMemory[i])));

                return varInfoInAdditionalCode;
        }

        private int GetCommandNumber(int positionInMemory)
        {
            return this.ramMemory.GetCell(positionInMemory).GetValue();
        }
        public override void GoToNextAddress()
        {
            if (CommandIsLong(GetCurrentCommandNumber()))
                currentAddress += 2;
            else
                currentAddress++;
        }
        public int GetTransitAddress()
        {
            if (GetCurrentCommandNumber() == COMMAND_SECOND_PART)
                return ramMemory.GetCell(currentAddress).GetItem()[3] - 1;
            else
                return ramMemory.GetCell(currentAddress).GetItem()[3];
        }

        #region Get operand
        public int GetCpuMemoryCell(int position)
        {
            if (position > REGISTER_NUMBER - 1)
                throw new Exception("Memory bound violation");
            if (cpuMemory[position] == Int32.MaxValue)
                throw new Exception("Appealing to a undefined register");

            return cpuMemory[position];
        }
        public void SetCpuMemoryCell(int position, int value)
        {
            if (position > 15)
                throw new Exception("Register set bounds violation");

            cpuMemory[position] = value;
        }
        public override int GetValueOperand(int positionInMemory, int numberOfOperand)
        {
            CheckNumberOfOperand(numberOfOperand);

            if (numberOfOperand == 1)
                return GetCpuMemoryCell(GetFirstOperandAddress(positionInMemory));
            else
            {
                if (CommandIsLong(GetCommandNumber(positionInMemory)))
                    return ramMemory.GetCell(GetAddressOperand(positionInMemory, numberOfOperand)).GetValue();
                else
                    return GetCpuMemoryCell(GetRRSecondOperandAddress(positionInMemory));
            }

        }
        public override int GetAddressOperand(int positionInMemory, int numberOfOperand)
        {
            CheckNumberOfOperand(numberOfOperand);

            if (numberOfOperand == 1)
                return GetFirstOperandAddress(positionInMemory);
            else
            {
                if (CommandIsLong(GetCommandNumber(positionInMemory)))
                    return GetRMSecondOperandAddress(positionInMemory);
                else
                    return GetRRSecondOperandAddress(positionInMemory);
            }
        }
        protected override void CheckNumberOfOperand(int numberOfOperand)
        {
            if (numberOfOperand < 0 || numberOfOperand > 2)
                throw new Exception("Invalid number of operand!");
        }
        private int GetRMSecondOperandAddress(int positionInMemory)
        {
            if (ramMemory.GetCell(positionInMemory).GetItem()[2] == 0)
                return ramMemory.GetCell(positionInMemory).GetItem()[3];
            else
                return ramMemory.GetCell(positionInMemory).GetItem()[3] +
                (GetCpuMemoryCell(ramMemory.GetCell(positionInMemory).GetItem()[2]) * 2);
        }
        private int GetRRSecondOperandAddress(int positionInMemory)
        {
            return ramMemory.GetCell(positionInMemory).GetItem()[2];
        }
        private int GetFirstOperandAddress(int positionInMemory)
        {
            return ramMemory.GetCell(positionInMemory).GetItem()[1];
        }

        #endregion

        public override int GetInOutOperand()
        {
            const int SECOND_OPERAND = 2;
            return SECOND_OPERAND;
        }
        public override void SetOperationResultInMemory(MemoryItem arithmeticResult)
        {
            SetCpuMemoryCell(GetAddressOperand(currentAddress, 1), arithmeticResult.GetValue());
        }
        public override void SetOperationResultInMemory(MemoryItem divisionResult, MemoryItem module)
        {
            SetCpuMemoryCell(GetAddressOperand(currentAddress, 1), divisionResult.GetValue());
            SetCpuMemoryCell(GetAddressOperand(currentAddress, 1) + 1, module.GetValue());
        }
        public override void SetVariableInMemory(int positionInMemory, int value)
        {
            ramMemory.SetCell(positionInMemory, new Variable(value));
            ramMemory.SetCell(positionInMemory + 1, new Variable(value));
        }

        #endregion

    }
}
