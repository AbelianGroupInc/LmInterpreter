using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LM2: LM, ILMOperations
    {
        private List<bool> comparisonOperations;
        public enum ComparisonFlag { EQUAL, N_EQUAL, LESS, GREATER, LESS_OR_EQUAL, GREATER_OR_EQUAL, INS_LESS, INS_GREATER, INS_LESS_OR_EQUAL, INS_GREATER_OR_EQUAL };
        #region Commands defines
            const int 
                CMD_COMPARE                   = 5,
	            CMD_INPUT                     = 6,
	            CMD_OUTPUT                    = 7,
	            CMD_UNSIGNED_INPUT            = 22,
	            CMD_UNSIGNED_OUTPUT           = 23,
	            CMD_ADD                       = 1,
	            CMD_SUBSTRACT                  = 2,
	            CMD_MULTIPLICATION            = 3,
	            CMD_DIVISION                  = 4,
	            CMD_UNSIGNED_MULTIPLICATION   = 19,
	            CMD_UNSIGNED_DIVISION         = 20,
	            CMD_ASSIGMENT                 = 0,
	            CMD_GOTO                      = 128,
	            CMD_LESS                      = 131,
	            CMD_GREATER                   = 133,
	            CMD_LESS_OR_EQUAL             = 134,
	            CMD_GREATER_OR_EQUAL          = 132,
	            CMD_EQUAL                     = 129,
	            CMD_NOT_EQUAL                 = 130,
	            CMD_UNSIGNED_LESS             = 147,
	            CMD_UNSIGNED_GREATER          = 149,
	            CMD_UNSIGNED_LESS_OR_EQUAL    = 150,
	            CMD_UNSIGNED_GREATER_OR_EQUAL = 148,
	            CMD_STOP                      = 153;
        #endregion

        public LM2():base(){
            comparisonOperations = new List<bool>(10);
        }

        #region Main methods
        
       /* public override void SetProgram(List<List<int > > parsedProgramText)
        {
            if (parsedProgramText.Count == 0)
                throw new Exception("");
            //The program is empty

            if(parsedProgramText[0][0] >= 0 && parsedProgramText[0][0] <= MAX_MEMORY_SIZE)
                currentAddress = parsedProgramText[0][0];

            for(int i = 0; i < parsedProgramText.Count; i++){
                if(parsedProgramText[i][0] >= 0 && parsedProgramText[i][0] <= MAX_MEMORY_SIZE){
                    InitialiseCommand(parsedProgramText[i]);
                }
                else
                {
                    throw new Exception();
                    //Runtime: Memory bounds violation
                }
            }
            if (!end)
                throw new Exception();
            //Runtime: Lost end of program

        }
        */

        protected override void InitialiseCommand(List<int> command)
        {
            try
            {
                CheckCommandFormat(command);

                this.ramMemory.SetCell(command[0], new LM2Command(command[1],
                    command[2], command[3]));
            }
            catch (Exception exp)
            {
                //char* temp = new char[strlen(exp.what()) + 1];
                //strcpy(temp, exp.what());
                //throw InterpreterException(temp, i + 1);
            }
        }

        private void CheckCommandFormat(List<int> command)
        {
            if (command.Count < 4)
                throw new Exception("Too few fields");
            else if (command.Count > 4)
                throw new Exception("Too many fields");
        }
        public override void DoOneStep(RichTextBox output)
        {
            if (this.endFlag)
                throw new Exception();
            //Program ended
            if (this.inputFlag)
                throw new Exception();
            //The value isn't entered
            switch (this.GetCurrentCommandNumber())
            {
                case CMD_COMPARE:
                    PerformFlagDetermination();
                    break;

                case CMD_OUTPUT:
                    PerformOutputOperation(LMCommands.Output, output);
                    break;
                case CMD_INPUT:
                    this.inputFlag = true;
                    break;
                case CMD_UNSIGNED_OUTPUT:
                    PerformOutputOperation(LMCommands.UnsignedOuput, output);
                    break;
                case CMD_UNSIGNED_INPUT:
                    this.inputFlag = true;
                    break;

                case CMD_ADD:
                    PerformArithmeticOperation(LMCommands.Add);
                    break;
                case CMD_SUBSTRACT:
                    PerformArithmeticOperation(LMCommands.Substract);
                    break;
                case CMD_MULTIPLICATION:
                    PerformArithmeticOperation(LMCommands.Multiplication);
                    break;
                case CMD_DIVISION:
                    PerformArithmeticOperation(LMCommands.Division);
                    break;
                case CMD_UNSIGNED_MULTIPLICATION:
                    PerformArithmeticOperation(LMCommands.UnsignedMultiplication);
                    break;
                case CMD_UNSIGNED_DIVISION:
                    PerformArithmeticOperation(LMCommands.UnsignedDivision);
                    break;

                case CMD_ASSIGMENT:
                    PerformAssignmentOperation();
                    break;

                case CMD_GOTO:
                    PerformGoToOperation();
                    break;

                case CMD_LESS:
                    PerformComparisonOperation(ComparisonFlag.LESS);
                    break;
                case CMD_GREATER:
                    PerformComparisonOperation(ComparisonFlag.GREATER);
                    break;
                case CMD_LESS_OR_EQUAL:
                    PerformComparisonOperation(ComparisonFlag.LESS_OR_EQUAL);
                    break;
                case CMD_GREATER_OR_EQUAL:
                    PerformComparisonOperation(ComparisonFlag.GREATER_OR_EQUAL);
                    break;
                case CMD_EQUAL:
                    PerformComparisonOperation(ComparisonFlag.EQUAL);
                    break;
                case CMD_NOT_EQUAL:
                    PerformComparisonOperation(ComparisonFlag.N_EQUAL);
                    break;

                case CMD_UNSIGNED_LESS:
                    PerformComparisonOperation(ComparisonFlag.INS_LESS);
                    break;
                case CMD_UNSIGNED_GREATER:
                    PerformComparisonOperation(ComparisonFlag.INS_GREATER);
                    break;
                case CMD_UNSIGNED_LESS_OR_EQUAL:
                    PerformComparisonOperation(ComparisonFlag.INS_LESS_OR_EQUAL);
                    break;
                case CMD_UNSIGNED_GREATER_OR_EQUAL:
                    PerformComparisonOperation(ComparisonFlag.INS_GREATER_OR_EQUAL);
                    break;
                case CMD_STOP:
                    this.endFlag = true;
                    break;
                default:
                    new Exception();
                    break;
            }
        }

        #endregion

        #region Axuiliary methods
        protected override void GoToNextAddress()
        {
            this.currentAddress++;
        }
        public override int GetValueOperand(int positionInMemory, int numberOfOperand)
        {
            if (positionInMemory < 0 || positionInMemory > MAX_MEMORY_SIZE)
                throw new Exception();
            //Memory bounds violation

            if (numberOfOperand < 0 || numberOfOperand > 2)
                throw new Exception();
            //Invalid number of operand
            return this.ramMemory.GetCell(this.ramMemory.GetCell(positionInMemory).GetItem()[numberOfOperand]).GetValue();
        }
        public override int GetAddressOperand(int positionInMemory, int numberOfOperand)
        {

            if (positionInMemory < 0 || positionInMemory > MAX_MEMORY_SIZE)
                throw new Exception();
            //Memory bounds violation

            if (numberOfOperand < 0 || numberOfOperand > 2)
                throw new Exception();
            //Invalid number of operand

            return this.ramMemory.GetCell(positionInMemory).GetItem()[numberOfOperand];
        }
        public override void InitVariable(int position, string name)
        {
            this.ramMemory.SetName(position, name);
        }
        public override void InitVariable(int position, int value)
        {
            this.ramMemory.SetCell(position, new Variable(value));
        }
        public override void InitVariable(int position, string name, int value)
        {
            InitVariable(position, name);
            InitVariable(position, value);
        }
        #endregion

        #region ILMOperations realisation
        public void PerformArithmeticOperation(Func<MemoryItem, MemoryItem, MemoryItem> arithmeticDelegate)
        {
            MemoryItem var1 = new Variable(GetValueOperand(this.currentAddress, 1));
            MemoryItem var2 = new Variable(GetValueOperand(this.currentAddress, 2));

            this.ramMemory.SetCell(GetAddressOperand(this.currentAddress, 1), arithmeticDelegate(var1, var2));
            //possible mistake with module
            if (arithmeticDelegate.Method.Name == "Division" || arithmeticDelegate.Method.Name == "UnsignedDivision")
                this.ramMemory.SetCell(GetAddressOperand(this.currentAddress, 1) + 1, LMCommands.Module(var1, var2));

            GoToNextAddress();
        }
        public void PerformFlagDetermination()
        {
            MemoryItem var1 = new Variable(GetValueOperand(this.currentAddress, 1));
            MemoryItem var2 = new Variable(GetValueOperand(this.currentAddress, 2));


            comparisonOperations[(int)ComparisonFlag.EQUAL] = LMCommands.Equal(var1, var2);
            comparisonOperations[(int)ComparisonFlag.N_EQUAL] = LMCommands.NotEqual(var1, var2);
            comparisonOperations[(int)ComparisonFlag.LESS] = LMCommands.Less(var1, var2);
            comparisonOperations[(int)ComparisonFlag.GREATER] = LMCommands.Greater(var1, var2);
            comparisonOperations[(int)ComparisonFlag.LESS_OR_EQUAL] = LMCommands.LessOrEqual(var1, var2);
            comparisonOperations[(int)ComparisonFlag.GREATER_OR_EQUAL] = LMCommands.GreaterOrEqual(var1, var2);
            comparisonOperations[(int)ComparisonFlag.INS_LESS] = LMCommands.UnsignedLess(var1, var2);
            comparisonOperations[(int)ComparisonFlag.INS_GREATER] = LMCommands.UnsignedGreater(var1, var2);
            comparisonOperations[(int)ComparisonFlag.INS_LESS_OR_EQUAL] = LMCommands.UnsignedLessOrEqual(var1, var2);
            comparisonOperations[(int)ComparisonFlag.INS_GREATER_OR_EQUAL] = LMCommands.UnsignedGreaterOrEqual(var1, var2);

            GoToNextAddress();
        }
        public void PerformComparisonOperation(ComparisonFlag flag)
        {
            this.currentAddress = comparisonOperations[(int)flag] ? GetAddressOperand(this.currentAddress, 1) : this.currentAddress + 1;
        }
        public void PerformInputOperation(int value)
        {
            MemoryItem var = new Variable(value);

            this.ramMemory.SetCell(GetAddressOperand(this.currentAddress, 1), var);

            this.inputFlag = false;
            GoToNextAddress();

        }
        public void PerformOutputOperation(Action<RichTextBox, MemoryItem, string> outputDelegate,
            RichTextBox output)
        {
            MemoryItem var = new Variable(this.GetValueOperand(this.currentAddress, 1));

            outputDelegate(output, var, this.ramMemory.GetName(GetAddressOperand(this.currentAddress, 1)));

            GoToNextAddress();
        }
        public void PerformAssignmentOperation()
        {
            int inPosition = GetAddressOperand(this.currentAddress, 1);
            int value = GetValueOperand(this.currentAddress, 2);

            MemoryItem var = new Variable(value);

            this.ramMemory.SetCell(inPosition, var);

            GoToNextAddress();
        }
        public void PerformGoToOperation()
        {
            this.currentAddress = this.GetAddressOperand(this.currentAddress, 1);
        }

        #endregion
    }
}
