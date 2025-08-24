#include <bits/stdc++.h> 
using namespace std; 

// A utility function to get the middle index of a given range
int get_middle_index(int start, int end) { 
    return start + (end - start) / 2; 
} 

/* A recursive function to get the sum of values in the given range 
   of the array. 
   Parameters:
   segment_tree --> Pointer to segment tree 
   node_index --> Index of current node in the segment tree 
   segment_start & segment_end --> Starting and ending indexes of the segment represented by node_index
   query_start & query_end --> Starting and ending indexes of the query range */
int get_range_sum_util(int *segment_tree, int segment_start, int segment_end, int query_start, int query_end, int node_index) { 
    // If the segment is completely within the given range, return its sum
    if (query_start <= segment_start && query_end >= segment_end) 
        return segment_tree[node_index]; 

    // If the segment is completely outside the given range
    if (segment_end < query_start || segment_start > query_end) 
        return 0; 

    // If the segment partially overlaps with the given range
    int middle = get_middle_index(segment_start, segment_end); 
    return get_range_sum_util(segment_tree, segment_start, middle, query_start, query_end, 2 * node_index + 1) + 
           get_range_sum_util(segment_tree, middle + 1, segment_end, query_start, query_end, 2 * node_index + 2); 
} 

/* A recursive function to update segment tree nodes affected by an update operation.
   Parameters:
   segment_tree --> Pointer to segment tree
   segment_start & segment_end --> Start and end indexes of the current segment
   index --> Index of the element to be updated in the input array
   difference --> Value to be added to the affected nodes
   node_index --> Index of the current node in the segment tree */
void update_segment_tree_util(int *segment_tree, int segment_start, int segment_end, int index, int difference, int node_index) { 
    // If the index is outside the range of this segment, return
    if (index < segment_start || index > segment_end) 
        return; 

    // Update the current node and propagate changes down if necessary
    segment_tree[node_index] += difference; 
    if (segment_end != segment_start) { 
        int middle = get_middle_index(segment_start, segment_end); 
        update_segment_tree_util(segment_tree, segment_start, middle, index, difference, 2 * node_index + 1); 
        update_segment_tree_util(segment_tree, middle + 1, segment_end, index, difference, 2 * node_index + 2); 
    } 
} 

// Function to update a value in the input array and reflect the change in the segment tree
void update_segment_tree(int input_array[], int *segment_tree, int size, int index, int new_value) { 
    // Check for invalid index
    if (index < 0 || index > size - 1) { 
        cout << "Invalid Input"; 
        return; 
    } 

    // Calculate the difference and update the array
    int difference = new_value - input_array[index]; 
    input_array[index] = new_value; 

    // Update the values in the segment tree
    update_segment_tree_util(segment_tree, 0, size - 1, index, difference, 0); 
} 

// Function to return sum of elements in the given range
int get_range_sum(int *segment_tree, int size, int query_start, int query_end) { 
    // Check for invalid range
    if (query_start < 0 || query_end > size - 1 || query_start > query_end) { 
        cout << "Invalid Input"; 
        return -1; 
    } 

    return get_range_sum_util(segment_tree, 0, size - 1, query_start, query_end, 0); 
} 

// A recursive function to construct the segment tree
int construct_segment_tree_util(int input_array[], int segment_start, int segment_end, int *segment_tree, int node_index) { 
    // If there is only one element in the array, store it in the segment tree node
    if (segment_start == segment_end) { 
        segment_tree[node_index] = input_array[segment_start]; 
        return input_array[segment_start]; 
    } 

    // Recursively construct left and right subtrees and store their sum in this node
    int middle = get_middle_index(segment_start, segment_end); 
    segment_tree[node_index] = construct_segment_tree_util(input_array, segment_start, middle, segment_tree, 2 * node_index + 1) + 
                               construct_segment_tree_util(input_array, middle + 1, segment_end, segment_tree, 2 * node_index + 2); 
    return segment_tree[node_index]; 
} 

/* Function to construct segment tree from given array.
   Allocates memory for segment tree and calls construct_segment_tree_util() */
int *construct_segment_tree(int input_array[], int size) { 
    // Compute the height of the segment tree
    int height = (int)(ceil(log2(size))); 

    // Compute the maximum size of the segment tree
    int max_size = 2 * (int)pow(2, height) - 1; 

    // Allocate memory for the segment tree
    int *segment_tree = new int[max_size]; 

    // Construct the segment tree
    construct_segment_tree_util(input_array, 0, size - 1, segment_tree, 0); 

    // Return the constructed segment tree
    return segment_tree; 
} 

// Driver program to test the segment tree functions
int main() { 
    int input_array[] = {1, 3, 5, 7, 9, 11}; 
    int size = sizeof(input_array) / sizeof(input_array[0]); 

    // Build segment tree from the given array 
    int *segment_tree = construct_segment_tree(input_array, size); 

    // Print sum of values in array from index 1 to 3 
    cout << "Sum of values in given range = " << get_range_sum(segment_tree, size, 1, 3) << endl; 

    // Update: set input_array[1] = 10 and update the segment tree 
    update_segment_tree(input_array, segment_tree, size, 1, 10); 

    // Print sum after the value is updated 
    cout << "Updated sum of values in given range = " << get_range_sum(segment_tree, size, 1, 3) << endl; 
    
    return 0; 
} 
