class Solution:
      def constructRectangle(self, area: int) -> List[int]:
        for i in range(1,int(sqrt(area)+1)):
            if area%i==0:
                res=(area//i,i)
        return res
                    
        
        