//One of the use cases of the stacks is checking the balanced brackets.
string isBalanced(string s) {
    int length = s.length();

    if(length == 0) return "YES"; //case 1 : An empty string
    else{//case 2 : A non-empty string

    vector<char> stack = {}; // create a stack to store opening brackets.
    for(int i = 0; i < length; i++){
        // check whether the bracket is an opening bracket and push it to the stack.
        if((s[i]=='{') ||( s[i]=='[') || (s[i]=='(')) stack.push_back(s[i]);

        else{ // it is a closing bracket.

            char close_bracket = s[i];

            if(stack.size() == 0) return "NO"; // If the stack is empty nothing to compare

            char open_bracket = stack.back(); //get the previously opened bracket.
            stack.pop_back(); // delete that from the stack.

            //check whether brackets are not matched.
            if((close_bracket == ')') && open_bracket != '(') return "NO"; // Previously opened bracket is not matched with the closed bracket.
            if((close_bracket == ']') && open_bracket != '[') return "NO"; // Previously opened bracket is not matched with the closed bracket.
            if((close_bracket == '}') && open_bracket != '{') return "NO"; // Previously opened bracket is not matched with the closed bracket.
        }
    }
    // checking for excess brackets if there is any.
    if(stack.size() ==0) return "YES";
    else return "NO";

    }

}
