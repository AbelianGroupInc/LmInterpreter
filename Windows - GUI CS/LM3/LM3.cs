using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LM3 : LM
    {
        #region Commands defines
        protected const int
            CMD_INPUT = 6,
            CMD_OUTPUT = 7,
            CMD_UNSIGNED_INPUT = 22,
            CMD_UNSIGNED_OUTPUT = 23,
            CMD_ADD = 1,
            CMD_SUBSRACT = 2,
            CMD_MULTIPLICATION = 3,
            CMD_DIVISION = 4,
            CMD_UNSIGNED_MULTIPLICATION = 19,
            CMD_UNSIGNED_DIVISION = 20,
            CMD_ASSIGMENT = 0,
            CMD_GOTO = 128,
            CMD_LESS = 131,
            CMD_GREATER = 133,
            CMD_LESS_OR_EQUAL = 134,
            CMD_GREATER_OR_EQUAL = 132,
            CMD_EQUAL = 129,
            CMD_NOT_EQUAL = 130,
            CMD_UNSIGNED_LESS = 147,
            CMD_UNSIGNED_GREATER = 149,
            CMD_UNSIGNED_LESS_OR_EQUAL = 150,
            CMD_UNSIGNED_GREATER_OR_EQUAL = 148,
            CMD_STOP = 153;
        #endregion

        public LM3() : base() { }

        #region Main methods
        public override void SetVariableInMemory(int positionInMemory, int value)
        {
            ramMemory.SetCell(positionInMemory, new Variable(value));
        }

        protected override void InitialiseCommand(List<int> command)
        {
            try
            {
                CheckCommandFormat(command);

                if (currentAddress == -1)
                    currentAddress = command[0];

                ramMemory.SetCell(command[0], new LM3Command(command[1], command[2], command[3], command[4]));
            }
            catch (Exception exp)
            {
                throw new System.Exception("At address \"" + TextFormat.addZeros(
                    Convert.ToString(command[0], 16), 4) + "\" " + exp.Message);
            }
        }
        private void CheckCommandFormat(List<int> command)
        {
            if (command.Count < 5)
                throw new Exception("Too few fields");
            else if (command.Count > 5)
                throw new Exception("Too many fields");
        }
        protected override void MasterSwitch(RichTextBox textbox)
        {
            switch (GetCurrentCommandNumber())
            {
                case CMD_INPUT:
                    LMCommands.InputMessage(textbox, GetName(GetAddressOperand(currentAddress, 1)));
                    inputFlag = true;
                    break;
                case CMD_UNSIGNED_INPUT:
                    LMCommands.InputMessage(textbox, GetName(GetAddressOperand(currentAddress, 1)));
                    uInputFlag = true;
                    break;
                case CMD_OUTPUT:
                    LM3Operations.PerformOutputOperation(this, LMCommands.Output, textbox);
                    break;
                case CMD_UNSIGNED_OUTPUT:
                    LM3Operations.PerformOutputOperation(this, LMCommands.UnsignedOuput, textbox);
                    break;
                case CMD_ADD:
                    LM3Operations.PerformArithmeticOperation(this,LMCommands.Add);
		            break;
	            case CMD_SUBSRACT:
                    LM3Operations.PerformArithmeticOperation(this,LMCommands.Substract);
		            break;
	            case CMD_MULTIPLICATION:
                    LM3Operations.PerformArithmeticOperation(this,LMCommands.Multiplication);
		            break;
	            case CMD_DIVISION:
                    LM3Operations.PerformDivisionOperation(this,LMCommands.Division,LMCommands.Module);
		            break;
	            case CMD_UNSIGNED_MULTIPLICATION:
                    LM3Operations.PerformArithmeticOperation(this,LMCommands.UnsignedMultiplication);
		            break;
	            case CMD_UNSIGNED_DIVISION:
                    LM3Operations.PerformDivisionOperation(this,LMCommands.UnsignedDivision,LMCommands.UnsignedModule);
		            break;
	            case CMD_ASSIGMENT:
                    LM3Operations.PerformAssignmentOperation(this);
		            break;
	            case CMD_GOTO:
                    LM3Operations.PerformGoToOperation(this);
		            break;
	            case CMD_LESS:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.Less);
		            break;
	            case CMD_GREATER:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.Greater);
		            break;
	            case CMD_LESS_OR_EQUAL:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.LessOrEqual);
		            break;
	            case CMD_GREATER_OR_EQUAL:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.GreaterOrEqual);
		            break;
	            case CMD_EQUAL:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.Equal);
		            break;
	            case CMD_NOT_EQUAL:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.NotEqual);
		            break;
	            case CMD_UNSIGNED_LESS:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.UnsignedLess);
		            break;
	            case CMD_UNSIGNED_GREATER:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.UnsignedGreater);
		            break;
	            case CMD_UNSIGNED_LESS_OR_EQUAL:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.UnsignedLessOrEqual);
		            break;
	            case CMD_UNSIGNED_GREATER_OR_EQUAL:
                    LM3Operations.PerformComparisonOperation(this, LMCommands.UnsignedGreaterOrEqual);
		            break;
                case CMD_STOP:
                    endFlag = true;
                    return;
                default:
                    break;
            }
        }
        #endregion

        #region Auxiliary methods
        public override void GoToNextAddress()
        {
            currentAddress++;
        }
        public override int GetValueOperand(int positionInMemory, int numberOfOperand)
        {
            CheckNumberOfOperand(numberOfOperand);

            return this.ramMemory.GetCell(ramMemory.GetCell(positionInMemory).GetItem()[numberOfOperand]).GetValue();
        }
        public override int GetAddressOperand(int positionInMemory, int numberOfOperand)
        {
            CheckNumberOfOperand(numberOfOperand);

            return this.ramMemory.GetCell(positionInMemory).GetItem()[numberOfOperand];
        }
        protected override void CheckNumberOfOperand(int numberOfOperand)
        {
            if (numberOfOperand < 0 || numberOfOperand > 3)
                throw new Exception("Invalid number of operand!");
        }

        public override void SetOperationResultInMemory(MemoryItem arithmeticResult)
        {
            ramMemory.SetCell(GetAddressOperand(currentAddress, 3), arithmeticResult);
        }
        public override void SetOperationResultInMemory(MemoryItem divisionResult, MemoryItem module)
        {
            ramMemory.SetCell(GetAddressOperand(currentAddress, 3), divisionResult);
            ramMemory.SetCell(GetAddressOperand(currentAddress, 3) + 1, module);
        }

        #endregion

    }
}
