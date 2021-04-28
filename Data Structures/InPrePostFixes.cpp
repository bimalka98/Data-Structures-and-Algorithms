/*
EvaluatePostfix(exp){
create a stack
for i =0 to length of exp-1{
if (exp[i]) is operand push(exp[i])
else if (exp[i] is operator){
op2 = top(); pop()
op1 = top(); pop()
result = perform(exp[i], op1, op2)
}
}
return top of stack
}
*/

/*
EvaluatePrefix(exp){
create a stack
for i =0 to length of exp-1{
if (exp[i]) is operand push(exp[i])
else if (exp[i] is operator){
op1 = top(); pop()
op2 = top(); pop() // only change in this pop from the above 
result = perform(exp[i], op1, op2)
}
}
return top of stack
}
*/
