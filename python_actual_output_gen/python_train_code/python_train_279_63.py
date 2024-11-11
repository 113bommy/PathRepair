# int(input())
# [int(s) for s in input().split()]
# input()
 
 
def solve():
    n1 ,n2, k1, k2 = [int(s) for s in input().split()]
    if n1 >= n2:
        print("Second")
    else:
        print("First")
 
 
 
if __name__ == "__main__":
    solve()