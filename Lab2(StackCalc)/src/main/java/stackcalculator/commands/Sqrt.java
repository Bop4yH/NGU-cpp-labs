package stackcalculator.commands;

import stackcalculator.commands.context.Context;
import stackcalculator.exceptions.StackAmountElements;
import stackcalculator.exceptions.StackCalculatorExceptions;
import stackcalculator.exceptions.WrongNumberOfArguments;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Sqrt implements ICommand {
    private final static Logger logger = Logger.getLogger(Sqrt.class.getName());
    @Override
    public void execute(Context context, String[] args) throws StackCalculatorExceptions {
        if (args == null || args.length != 0)
            throw new WrongNumberOfArguments("WrongArguments exceptions for SQRT");

        if (context.getStackSize() < 1)
            throw new StackAmountElements("The stack doesn't have the right amount for SQRT");

        context.push(Math.sqrt(context.pop()));
        logger.log(Level.FINE,"Successfully did operation {0}", this.getClass().getName());
    }
}
