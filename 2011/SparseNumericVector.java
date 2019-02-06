

package A1Q1;
import java.util.*;

/**
 * Represents a sparse numeric vector. Elements are comprised of a (long)
 * location index an a (double) value.  The vector is maintained in increasing
 * order of location index, which facilitates numeric operations like
 * inner products (projections).  Note that location indices can be any integer
 * from 1 to Long.MAX_VALUE.  The representation is based upon a
 * singly-linked list.
 * The following methods are supported:  iterator, getSize, getFirst,
 * add, remove, and dot, which takes the dot product of the with a second vector
 * passed as a parameter.
 * @author jameselder
 */
public class SparseNumericVector implements Iterable {

    protected SparseNumericNode head = null;
    protected SparseNumericNode tail = null;
    protected long size;

  /**
     * Iterator
     */
    @Override
    public Iterator<SparseNumericElement> iterator() { //iterator
        return new SparseNumericIterator(this);
    }

    /**
     * @return number of non-zero elements in vector
     */
   public long getSize() {
        return size;
    }

     /**
     * @return the first node in the list.
     */
    public SparseNumericNode getFirst() {
        return head;
    }
    
    /**
     * Add the element to the vector.  It is inserted to maintain the
     * vector in increasing order of index.  If the element has zero value, or if 
     * an element with the same index already exists, an UnsupportedOperationException is thrown. 
     * @param e element to add
     */
  public void add(SparseNumericElement e) throws UnsupportedOperationException {
	  
	  	//SparseNumericElement element = new SparseNumericElement(e.getIndex(),e.getValue());
	  	
	  	//SparseNumericElement Next = Current.getElement.getNext();
	  	SparseNumericNode Node = new SparseNumericNode(e,null);
	  	SparseNumericNode Current = this.head;
	  	//SparseNumericNode Next = Current.getNext();
	  	if(head==null || tail == null){
	  	this.head = Node;
	  	tail=head;}
	  	
	  	
	  	{while(Current != null){
	  		
	  		
	  	
	  		//SparseNumericNode CurrentNext = Current.getNext();
	  	}
	  		
	  		if(Current.getElement().getValue() == 0 && Current.getElement().getIndex() == e.getIndex()){
	  		throw new UnsupportedOperationException();
	  		}
	  			
	  		
	  		else if (Current.getElement().getIndex() < e.getIndex()){
	  		Current=Current.getNext();
	  		
	  		
	  		
	  	}else{
	  		Node.setNext(Current.getNext());
	  		Current.setNext(Node);
	  		size++;
	  		
	  	}
	  
           }
  }

    /**
     * If an element with the specified index exists, it is removed and the
     * method returns true.  If not, it returns false.
     *
     * @param index of element to remove
     * @return true if removed, false if does not exist
     */
    public boolean remove(Long index) {
    	SparseNumericNode start = head;
    	SparseNumericNode end =head.getNext();
    	
    	if(start.getElement().getIndex()==index){
    		this.head=end;
    		return true;
    	}
    	else{
    		while(start.getNext() !=null){
    			if(start.getNext().getElement().getIndex()==index){
    				start.setNext(start.getNext().getNext());
    				return true;
    			}
    			start=start.getNext();
    		}
    		//return false;
    	}
    	return false;
    }

    /**
     * Returns the inner product of the vector with a second vector passed as a
     * parameter.  The vectors are assumed to reside in the same space.
     * Runs in O(m+n) time, where m and n are the number of non-zero elements in
     * each vector.
     * @param Y Second vector with which to take inner product
     * @return result of inner product
     */

    public double dot (SparseNumericVector Y) {
        //implement this method
        //this return statement is here to satisfy the compiler - replace it with your code.
        return 0;
   }

       /**
     * returns string representation of sparse vector
     */

    @Override
    public String toString() {
        String sparseVectorString = "";
        Iterator<SparseNumericElement> it = iterator();
        SparseNumericElement x;
        while (it.hasNext()) {
            x = it.next();
            sparseVectorString += "(index " + x.getIndex() + ", value " + x.getValue() + ")\n";
        }
        return sparseVectorString;
    }
}
