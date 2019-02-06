package A1Q3;

import java.util.*;

/**
 * Specializes the stack data structure for comparable elements, and provides a
 * method for determining the maximum element on the stack in O(1) time.
 * 
 * @author jameselder
 */
public class MaxStack<E extends Comparable<E>> extends Stack<E> {

	private Stack<E> maxStack;

	public MaxStack() {
		maxStack = new Stack<>();
	}

	/* must run in O(1) time */
	public E push(E element) {
		int zero =0;
		
		

		if (maxStack.empty() || element.compareTo(maxStack.peek()) >= zero) {

			maxStack.add(element);


			super.add(element);
			
			
			
		} else {
			super.add(element);
		}
		return element;
	}

	/* @exception EmptyStackException if this stack is empty. */
	/* must run in O(1) time */
	public synchronized E pop() {

		if (super.isEmpty()) {
			throw new EmptyStackException();
			
			
		} else {

			if (super.peek().equals(maxStack.peek()) && !maxStack.empty()) {

				maxStack.pop();

				return super.pop();
			} else {
				return super.pop();
			}

		}

	}

	/* Returns the maximum value currenctly on the stack. */
	/* @exception EmptyStackException if this stack is empty. */
	/* must run in O(1) time */
	public synchronized E max() {

		if (maxStack.empty()) {
			throw new EmptyStackException();
		} else {
			return maxStack.peek();
		}

		// Dummy return to satisfy compiler. Remove once coded.
	}
}