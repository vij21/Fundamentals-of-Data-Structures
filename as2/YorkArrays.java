package A4Q1;
import java.util.*;

/**
 *
 * Provides two static methods for sorting Integer arrays (heapSort and mergeSort)

 */
public class YorkArrays {

    /* Sorts the input array of Integers a using HeapSort.  Result is returned in a.
     * Makes use of java.util.PriorityQueue.  
       Sorting is NOT in place - PriorityQueue allocates a separate heap-based priority queue. 
       Not a stable sort, in general.  
       Throws a null pointer exception if the input array is null.  */
    public static void heapSort(Integer[] a) throws NullPointerException {
       //implement this method.
    	if(a==null) {throw new NullPointerException();}
    	PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
    	for(int i = 0; i<a.length;i++) {
    		queue.add(a[i]);
    	}
    	for(int i = 0; i<a.length;i++) {
    		a[i]=queue.poll();
    	}
    }


    /* Sorts the input array of Integers a using mergeSort and returns result.
     * Sorting is stable.
       Throws a null pointer exception if the input array is null. */
    
      public static Integer[] mergeSort(Integer[] a)  throws NullPointerException {
      	if(a==null) {throw new NullPointerException();}
          return(mergeSort(a, 0, a.length-1));
        
     }

    /* Sorts the input subarray of Integers a[p...q] using MergeSort and returns result.
     * Sorting is stable.
     */
      private static Integer[] mergeSort(Integer[] a, int p, int q) {
    	  if(q-p<1) {
    		  Integer[] c = new Integer[1];
    		  c[0] = a[q];
    		  return c;
    	  }
    	  int mid =(q+p)/2;

    	  Integer[] s1=mergeSort(a,p,mid);
    	  Integer[] s2=mergeSort(a,mid+1,q);
    	  return merge(s1,s2);
      }
    
    /* Merges two sorted arrays of Integers into a single sorted array.  Given two
     * equal elements, one in a and one in b, the element in a precedes the element in b.
     */
      private static Integer[] merge(Integer[] a, Integer[] b) {
    	Integer[] c = new Integer[a.length+b.length];
    	int i = 0;
    	int j = 0;
    	while(i<a.length&&j<b.length) {
    		if(a[i]<b[j]) {
    			c[i+j]=a[i];
    			i++;
    		} else {
    			c[i+j]=b[j];
    			j++;
    		}
    	}
    	
    	while(i<a.length) {
    		c[i+j]=a[i];
    		i++;
    	}
    	
    	while(j<b.length) {
    		c[i+j]=b[j];
    		j++;
    	}
    	return c;
     }
    
}
