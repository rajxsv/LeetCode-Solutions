class Solution {
    public int findCenter(int[][] edges) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        int n = edges.length;
        int cnt = 0;
        
        for(int[] element: edges) {
            // hashMap.put(element, hashMap.get)
            int u = element[0];
            int v = element[1];
            
            if(hashMap.containsKey(u)) {
                hashMap.put(u, hashMap.get(u)+1);
            } else {
                hashMap.put(u, 1);
            }
            if(hashMap.get(u) == n) {
                return u;
            }
            
            if(hashMap.containsKey(v)) {
                hashMap.put(v, hashMap.get(v)+1);
            } else {
                hashMap.put(v, 1);
            }
            if(hashMap.get(v) == n) {
                return v;
            }
        }
        
        return cnt;
    }
}