''' CODED WITH LOVE BY SATYAM KUMAR '''


from sys import stdin, stdout
import cProfile, math
from collections import Counter
from bisect import bisect_left,bisect,bisect_right
import itertools
from copy import deepcopy
from fractions import Fraction
import sys, threading
sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

printHeap = str()
memory_constrained = False
P = 10**9+7
import sys
sys.setrecursionlimit(10000000)

class Operation:
    def __init__(self, name, function, function_on_equal, neutral_value=0):
        self.name = name
        self.f = function
        self.f_on_equal = function_on_equal
def add_multiple(x, count):
    return x * count
def min_multiple(x, count):
    return x
def max_multiple(x, count):
    return x
sum_operation = Operation("sum", sum, add_multiple, 0)
min_operation = Operation("min", min, min_multiple, 1e9)
max_operation = Operation("max", max, max_multiple, -1e9)
class SegmentTree:
    def __init__(self,
                 array,
                 operations=[sum_operation, min_operation, max_operation]):
        self.array = array
        if type(operations) != list:
            raise TypeError("operations must be a list")
        self.operations = {}
        for op in operations:
            self.operations[op.name] = op
        self.root = SegmentTreeNode(0, len(array) - 1, self)
    def query(self, start, end, operation_name):
        if self.operations.get(operation_name) == None:
            raise Exception("This operation is not available")
        return self.root._query(start, end, self.operations[operation_name])
    def summary(self):
        return self.root.values
    def update(self, position, value):
        self.root._update(position, value)
    def update_range(self, start, end, value):
        self.root._update_range(start, end, value)
    def __repr__(self):
        return self.root.__repr__()
class SegmentTreeNode:
    def __init__(self, start, end, segment_tree):
        self.range = (start, end)
        self.parent_tree = segment_tree
        self.range_value = None
        self.values = {}
        self.left = None
        self.right = None
        if start == end:
            self._sync()
            return
        self.left = SegmentTreeNode(start, start + (end - start) // 2,
                                    segment_tree)
        self.right = SegmentTreeNode(start + (end - start) // 2 + 1, end,
                                     segment_tree)
        self._sync()
    def _query(self, start, end, operation):
        if end < self.range[0] or start > self.range[1]:
            return None
        if start <= self.range[0] and self.range[1] <= end:
            return self.values[operation.name]
        self._push()
        left_res = self.left._query(start, end,
                                    operation) if self.left else None
        right_res = self.right._query(start, end,
                                      operation) if self.right else None
        if left_res is None:
            return right_res
        if right_res is None:
            return left_res
        return operation.f([left_res, right_res])
    def _update(self, position, value):
        if position < self.range[0] or position > self.range[1]:
            return
        if position == self.range[0] and self.range[1] == position:
            self.parent_tree.array[position] = value
            self._sync()
            return
        self._push()
        self.left._update(position, value)
        self.right._update(position, value)
        self._sync()
    def _update_range(self, start, end, value):
        if end < self.range[0] or start > self.range[1]:
            return
        if start <= self.range[0] and self.range[1] <= end:
            self.range_value = value
            self._sync()
            return
        self._push()
        self.left._update_range(start, end, value)
        self.right._update_range(start, end, value)
        self._sync()
    def _sync(self):
        if self.range[0] == self.range[1]:
            for op in self.parent_tree.operations.values():
                current_value = self.parent_tree.array[self.range[0]]
                if self.range_value is not None:
                    current_value = self.range_value
                self.values[op.name] = op.f([current_value])
        else:
            for op in self.parent_tree.operations.values():
                result = op.f(
                    [self.left.values[op.name], self.right.values[op.name]])
                if self.range_value is not None:
                    bound_length = self.range[1] - self.range[0] + 1
                    result = op.f_on_equal(self.range_value, bound_length)
                self.values[op.name] = result
    def _push(self):
        if self.range_value is None:
            return
        if self.left:
            self.left.range_value = self.range_value
            self.right.range_value = self.range_value
            self.left._sync()
            self.right._sync()
            self.range_value = None
    def __repr__(self):
        ans = "({}, {}): {}\n".format(self.range[0], self.range[1],
                                      self.values)
        if self.left:
            ans += self.left.__repr__()
        if self.right:
            ans += self.right.__repr__()
        return ans

def display(string_to_print):
    stdout.write(str(string_to_print) + "\n")

def primeFactors(n): #n**0.5 complex 
    factors = dict()
    for i in range(2,math.ceil(math.sqrt(n))+1):  
        while n % i== 0: 
            if i in factors:
                factors[i]+=1
            else: factors[i]=1
            n = n // i 
    if n>2:
        factors[n]=1
    return (factors)
    
def isprime(n):
    """Returns True if n is prime."""
    if n < 4:
        return True
    if n % 2 == 0:
        return False
    if n % 3 == 0:
        return False
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += w
        w = 6 - w
    return True

def test_print(*args):
    if testingMode:
        print(args)

def display_list(list1, sep=" "):
    stdout.write(sep.join(map(str, list1)) + "\n")

def get_int():
    return int(stdin.readline().strip())

def get_tuple():
    return map(int, stdin.readline().split())

def get_list():
    return list(map(int, stdin.readline().split()))

memory = dict()
def clear_cache():
    global memory
    memory = dict()
def cached_fn(fn, *args):
    global memory
    if args in memory:
        return memory[args]
    else:
        result = fn(*args)
        memory[args] = result
        return result


# -------------------------------------------------------------- MAIN PROGRAM
TestCases = True
testingMode = False
optimiseForReccursion = False #Can not be used clubbed with TestCases
            

def main():
    n,k= get_tuple()
    x = 0
    i = 0
    xs=[]
    if (k==0):
        print("YES "+str(n))
        return
    if (n==1):
        print("YES 0") if k==1 else print("NO")
        return
    while x<=k and i<n:
        x+=4**i
        xs.append(x)
        i+=1
   # print(xs)
    if x<k:
        print("NO")
        return
    elif k==3:
        print("YES "+str((n-1))) if n>2 else print("NO")
    else:
        for i,ele in enumerate(xs):
            if i==len(xs)-1:
                ind = len(xs)-1
              #  print(ind,"At end")
            else:
                if ele<=k and xs[i+1]>k:
                    ind = i+1
                   # print(ind,"inBW")
                    break
    
        #print(xs[ind-1]+(2*(2**(ind)-2)+3))
        if (xs[ind-1]+(2*(2**(ind)-2)+3)<=k) and n>1:
            ind+=1
        #print(ind,n)
        print("YES "+str((n-ind)))



    
        


        
            


# --------------------------------------------------------------------- END


if TestCases: 
    for _ in range(get_int()): 
        cProfile.run('main()') if testingMode else main() 
else: (cProfile.run('main()') if testingMode else main()) if not optimiseForReccursion else threading.Thread(target=main).start()