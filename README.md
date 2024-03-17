# ObjektinisProgramavimas
This is a repository for my VU study subject Objective Programming

## Specs
#### To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# Test 1
### Vector
    Time taken to read data:
    1000 students: 0.0225548s
    10000 students: 0.161925s
    100000 students: 1.53185s
    1000000 students: 15.0604s
    10000000 students: 157.078s

    Time taken to sort data:
    1000 students: 0.0060379s
    10000 students: 0.0560185s
    100000 students: 0.54057s
    1000000 students: 5.98002s
    10000000 students: 56.9632s

    Time taken to divide students in the file:
    1000 students: 0.000925204s
    10000 students: 0.00864535s
    100000 students: 0.0870169s
    1000000 students: 0.923641s 
    10000000 students: 10.0699s

### List
    Time taken to read data:
    1000 students: 0.0230061s
    10000 students: 0.163591s
    100000 students: 1.51784s
    1000000 students: 16.9385s
    10000000 students: 154.424s

    Time taken to sort data:
    1000 students: 0.00428305s
    10000 students: 0.0587323s
    100000 students: 0.727277s
    1000000 students: 10.051s
    10000000 students: 117.749s

    Time taken to divide students in the file:
    1000 students: 0.00102186s
    10000 students: 0.00875401s
    100000 students: 0.0931033s
    1000000 students: 1.01632s
    10000000 students: 9.35735s

### Deque
    Time taken to read data:
    1000 students: 0.021631s
    10000 students: 0.162111s
    100000 students: 1.50907s
    1000000 students: 15.497s
    10000000 students: 162.153s

    Time taken to sort data:
    1000 students: 0.00597704s
    10000 students: 0.0568725s
    100000 students: 0.541957s
    1000000 students: 5.85342s
    10000000 students: 60.6313s

    Time taken to divide students in the file:
    1000 students: 0.000888919s
    10000 students: 0.00879198s
    100000 students: 0.0869602s
    1000000 students: 1.08464s
    10000000 students: 9.41827s

> [!NOTE]
> P.S. Changing structure's type from vector into list or deque, programs speed would actually change.

**DATA READING**: The impact on reading might not be significant and caught by a human eye, but if we change **_vector_** into either **_list_** or **_deque_** the time would be a little bit smaller 

**SORTING DATA**: 
- **_Vector_** provides the fastest sorting because it allows random access (RA), which is super good for _quicksort_ algorithm used in _sort_.
- **_List_** has it's own _sort_ method which is optimized for list operations. It is **slower** than **_vector_** because it cannot access random access (RA). It is quite fast because it is designed for quick and efficient insertions and deletions.
- **_Deque_** is the slowest from these 3 because it doesn't support access to random access (RA) and is not designed for it, making it the **slowest** one.

**DIVIDING STUDENTS**: 
- Using **_vector_** dividing might involve a lot of element shifting, especially if you're erasing elements from the middle.
- **_List_** should be more efficient than a **_vector_** for dividing because it can insert and remove elements without shifting others.
- **_Deque_** is better than a vector for middle insertions/removals but not as efficient as a list because of it's design.

In summary, if the structure of Studentas is changed from a **_vector_** to a **_list_** or **_deque_**, you might see improved performance in certain operations (like dividing students) due to the **_list's_** and **_deque's_** efficient insertion and deletion capabilities. However, sorting might be slower, especially for **_deque_**. The exact impact would depend on the specific operations and how they are implemented.

> [!WARNING]
> When doing these tests try to do as many as you can, because from the first sight, the differences may not be seen because of the varying time all of the actions take 

# Test 2
### Strategy 1
#### Vector
    Time taken to read data:
    1000 students: 0.0228874s
    10000 students: 0.166344s
    100000 students: 1.59188s
    1000000 students: 15.4619s
    10000000 students: 

    Time taken to sort data:
    1000 students: 0.00589303s
    10000 students: 0.0552494s
    100000 students: 0.538313s
    1000000 students: 6.18915s
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 0.000935161s
    10000 students: 0.00835907s
    100000 students: 0.0876151s
    1000000 students: 1.10855s
    10000000 students: 

#### List
    Time taken to read data:
    1000 students: 0.0202555s
    10000 students: 0.166206s
    100000 students: 1.56521s
    1000000 students: 15.9532s
    10000000 students: 

    Time taken to sort data:
    1000 students: 0.00403285s
    10000 students: 0.0604099s
    100000 students: 0.799202s
    1000000 students: 10.1229s
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 0.000769389s
    10000 students: 0.0074186s
    100000 students: 0.0936631s
    1000000 students: 0.969208s
    10000000 students: 

#### Deque
    Time taken to read data:
    1000 students: 0.0232768s
    10000 students: 0.163882s
    100000 students: 1.56918s
    1000000 students: 16.0526s
    10000000 students: 

    Time taken to sort data:
    1000 students: 0.00670575s
    10000 students: 0.0587848s
    100000 students: 0.616905s
    1000000 students: 6.67419s
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 0.000968202s
    10000 students: 0.00842794s
    100000 students: 0.09097s
    1000000 students: 0.964875s
    10000000 students: 

#### Implementing this strategy:
- **_Vector_**: May have some problems when splitting students into 2 containers because of the need for additional memory.
- **_List_**: They don't require any additional memory when splitting students into 2 dfferent containers, but they are slower than vectors because of slower random acccess (RA).
- **_Deque_**: They are much more efficient when it comes to splitting compared to others. They support insertion and deletion from all ends. They offer quite a fast reading and insertion but are still slower than vectors due to no access to random access (RA).

>[!NOTE]
>In comparison, vectors excel in reading speed but suffer in sorting time compared to lists and deques. Lists offer quicker sorting but slower reading compared to vectors. Deques provide an intermediary performance, particularly when splitting occurs infrequently but still aren't very fast.

### Strategy 2
#### Vector
    Time taken to read data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to sort data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

#### List
    Time taken to read data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to sort data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

#### Deque
    Time taken to read data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to sort data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students:


### Strategy 3
#### Vector
    Time taken to read data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to sort data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

#### List
    Time taken to read data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to sort data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

#### Deque
    Time taken to read data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to sort data:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 

    Time taken to divide students in the file:
    1000 students: 
    10000 students: 
    100000 students: 
    1000000 students: 
    10000000 students: 
