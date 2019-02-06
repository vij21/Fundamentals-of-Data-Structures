package A2Q1;
import java.util.*;
/**
 * Represents a sorted integer array.  Provides a method, kpairSum, that
 * determines whether the array contains two elements that sum to a given
 * integer k.  Runs in O(n) time, where n is the length of the array.
 * @author jameselder
 */
public class SortedIntegerArray {

    protected int[] sortedIntegerArray;

    public SortedIntegerArray(int[] integerArray) {
        sortedIntegerArray = integerArray.clone();
        Arrays.sort(sortedIntegerArray);
    }
    
    private boolean kPairSumInterval(Integer k,int i,int j){
    	//int low = 0;
    	 //int high = sortedIntegerArray.length-1;
    	
    	
    	 if(sortedIntegerArray.length < 2){
    		 return false;
    		 
    	 }
     	while(j<sortedIntegerArray.length){

    	for (i= 0;i<sortedIntegerArray.length;i++){
    		int first = sortedIntegerArray[i];
    		int second = sortedIntegerArray[j];
    			long sum;

    		if (first+second == k && i !=j){
    		
    			return true;
    		}
    	
     	
		
			
		 
			//if (k==sum){
				
				//return true;
			
    	}
			
    	return kPairSumInterval(k,i,j+1);				
			//return false;
   
    }
return false;
    }


	
     	
		
    	
    
    

/**
 * Determines whether the array contains two elements that sum to a given
 * integer k. Runs in O(n) time, where n is the length of the array.
 * @author jameselder
 */
    public boolean kPairSum(Integer k) {
    	return kPairSumInterval(k,0,0);
    	//if (kPairSumInterval(k,0,0)){
    		//return true;
    	//}
    	// return kPairSumInterval(k,0,(sortedIntegerArray.length-1));
		//return false;
    		
    
    	
    	
    }
}