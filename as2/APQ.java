package A2Q2;

import java.util.*;

/**
 * Adaptible priority queue using location-aware entries in a min-heap, based on
 * an extendable array.  The order in which equal entries were added is preserved.
 *
 * @author jameselder
 * @param <E> The entry type.
 */
public class APQ<E> {

    private final ArrayList<E> apq; //will store the min heap
    private final Comparator<E> comparator; //to compare the entries
    private final Locator<E> locator;  //to locate the entries within the queue

    /**
     * Constructor
     * @param comparator used to compare the entries
     * @param locator used to locate the entries in the queue
     * @throws NullPointerException if comparator or locator parameters are null
     */
    public APQ(Comparator<E> comparator, Locator<E> locator) throws NullPointerException {
        if (comparator == null || locator == null) {
            throw new NullPointerException();
        }
        apq = new ArrayList<>();
        apq.add(null); //dummy value at index = 0
        this.comparator = comparator;
        this.locator = locator;
    }

    /**
     * Inserts the specified entry into this priority queue.
     *
     * @param e the entry to insert
     * @throws NullPointerException if parameter e is null
     */
    public void offer(E e) throws NullPointerException {
    //implement this method    
    }

   /**
     * Removes the entry at the specified location.
     *
     * @param pos the location of the entry to remove
     * @throws BoundaryViolationException if pos is out of range
     */
    public void remove(int pos) throws BoundaryViolationException {
    //implement this method
    	
    	if(pos <0 &&  pos > apq.size()-1 ) {
    		throw BoundaryViolationException();
    		
    		
    	}else{
    		
    		swap(pos,apq.size() -1);
    		apq.remove(apq.size()-1);
    		downheap(pos);
    		
    	}
    }

   /**
     * Removes the first entry in the priority queue.
     */
    public E poll() {
        //implement this method
    	
    	if (apq.isEmpty( )) {
    		return null;
    	}else{
       	 return apq.remove(apq.first( ));

    	}
	
    }

  /**
     * Returns but does not remove the first entry in the priority queue.
     */
     public E peek() {
        if (isEmpty()) {
            return null;
        }
        return apq.get(1);
    }

   public boolean isEmpty() {
        return (size() == 0);
 
    }

    public int size() {
        return apq.size() - 1; //dummy node at location 0
    }


    /**
     * Shift the entry at pos upward in the heap to restore the minheap property
     * @param pos the location of the entry to move
     */
    private void upheap(int pos) {
        //implement this method
	//you have to check if your parent of the position you’re at right is less than or equal, if not you make the current position your parent node.
    	
    	while (pos > 0) { // continue until reaching root (or break statement)
    		 E p = ((apq.get(pos/2)));
    		 
    		if (comparator.compare(apq.get(pos), apq.get(pos/2)) >= 0) break;     			 
    			 
    	}
    		 swap(pos, pos/2);
    		 pos = pos/2;
    }
    	
    

    /**
     * Shift the entry at pos downward in the heap to restore the minheap property
     * @param pos the location of the entry to move
     */
    private void downheap(int pos) {
	//Position you’re at right now is parent, you check both your children are greater than or equal the value 
// say parent is 2 and children are 1 and 8 , because 1 is one and two and then swap, if they both smaller then you compare both children to see which one is bigger, whichever one is bigger you 
        //implement this method
    	E p = apq.get(pos);
    	E p1 = apq.get(2 * pos);
    	E p2= apq.get(((2*pos)+1));
    	if(pos*2 <= apq.size()-1){
    	
		if (comparator.compare(apq.get(2*pos), apq.get(pos)) >= 0 && (comparator.compare(apq.get((2*pos)+1), apq.get(pos)) >=0))break;
		
			
    	}else if(comparator.compare(apq.get(2*pos), apq.get(pos)) < 0){
			
    	swap((2*pos)+1,pos);
    	
		}else if(comparator.compare(apq.get((2*pos)+1), apq.get(pos))<0){
			
    	swap (2*pos,pos);
    	
		}else {
			if (comparator.compare(apq.get(2*pos), apq.get((2*pos)+1))==0){
				swap (2*pos,pos);
			}
			else if(comparator.compare(apq.get(2*pos), apq.get((2*pos)+1))<0){ // comparing both children and if they are equal 
				swap((2*pos)+1,pos);//swap the left child and the parent 
			}
			else{
				swap(2*pos,pos);
			}
    
		}
    
		
    	
    
    }

    /**
     * Swaps the entries at the specified locations.
     *
     * @param pos1 the location of the first entry 
     * @param pos2 the location of the second entry 
     */
    private void swap(int pos1, int pos2) {
    	
    	E temp = apq.get(pos1);
    	apq.set(pos1, apq.get(pos2));
    	apq.set(pos2, temp);

	    
	    
	    
	   
	    
	    
	   
	    
        //implement this method
	//
    }
}