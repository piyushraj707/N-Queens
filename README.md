# N-Queens
Provide an arrangement of N queens through the array (of arrays) in the code itself and the program will tell if the provided arrangement satisfies the N-queen arrangement.

### What is N-Queens game
The eight queens puzzle is the problem of placing N chess queens on an N×N chessboard so that no two queens threaten each other; thus, a solution requires that no two queens share the same row, column, or diagonal. 

### Approach
This program uses logical reasoning to implement each condition required for a perfect arrangement. There are five total conditions.

### Condition 1
Veryfying that each row contain at least one queen.
$$ C_1=\land_{i=1}^n \lor_{j=1}^n p(i,j) $$

### Condition 2
Veryfying that each row contains at most one queen.
$$ C_2=\land_{i=1}^n \land_{j=1}^{n-1} \land _{k=j+1}^n(\lnot p(i,j)\lor \lnot p(i,k)) $$

### Condition 3
Veryfying that every column contains at most one queen:
$$ C_3=\land_{j=1}^n \land_{i=1}^{n-1} \land _{k=i+1}^n(\lnot p(i,j)\lor \lnot p(k,j)) $$

### Condition 4
Veryfying that no right-inclined diagonal contains two queens. 
$$ C_4=\land_{i=1}^{n-1} \land_{j=1}^{n-1} \land _{k=1}^{min(n-i,n-j)} (\lnot p(i,j)\lor \lnot p(i+k,j+k)) $$

### Condition 5
Veryfying that no left-inclined diagonal contains two queens. 
$$ C_5=\land_{i=2}^{n} \land_{j=1}^{n-1} \land _{k=1}^{min(i-1,n-j)} (\lnot p(i,j)\lor \lnot p(i-k,k+j)) $$

### Final step
After looking for correctness of each of the five conditions we now check whether all conditions are being satisfied at the same time. For this we evaluate the final result (f\textunderscore result) as:

$$ f\textunderscore result= C_1 \land C_2 \land C_3 \land C_4 \land C_5 $$
Note that failing of even any one of the five mentioned implies that the arragement is not correct and  $f\textunderscore result$ fails too. 
