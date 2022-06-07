class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> hash = new HashMap<Character, Integer>();
        for(int i=0; i<magazine.length(); i++){
            Character c = magazine.charAt(i);
            if(hash.containsKey(c))
                hash.put(c, hash.get(c) + 1);
            else
                hash.put(c, 1);
        }
        for(int i=0; i<ransomNote.length(); i++){
            Character c = ransomNote.charAt(i);
            if(!hash.containsKey(c)) return false;
            else{
                if(hash.get(c) == 0) return false;
                else{
                    hash.put(c, hash.get(c) - 1);
                }
            }
        }
        return true;
    }
}
