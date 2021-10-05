class Solution {
    public boolean isSubsequence(String s, String t) {
        int smol = s.length();
        int large = t.length();
        
        if(smol>large) return false;
        if(smol==large) return s.equals(t);
        if(smol==0) return true;
        
        // Stack<Character> st = new Stack<>();
        Stack<Character> dummy = new Stack<>();
        
        for(int i=0;i<t.length();i++){
            // st.push(t.charAt(i));
            dummy.push(t.charAt(i));
        }
        
        int i=0,j=0;
        Iterator iterator = dummy.iterator();
        while(iterator.hasNext() && i<smol){
            Object value = iterator.next();
            // System.out.print(value);
            Character ch = s.charAt(i);
            if(value==ch){
                System.out.printf("Matched at position: %d",i);
                i++;
                j++;
            }
        }
        
        // int i=smol-1, j=0;
        // while(st.empty()==false && i>=0){
        //     char x = st.pop();
        //     if(x==s.charAt(i)){
        //         i--;
        //         j++;
        //     }
        // }
        if(i==smol)
            return true;
        return false;
    }
}