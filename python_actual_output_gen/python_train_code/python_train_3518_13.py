import sys

def find_operation_sequence(a, b, n, count):
    #print("received: a = ", a, 
    #    ", b = ", b, 
    #    ", n = ", n,
    #    ", count = ", count, 
    #   sep = "")
    if a < b and b <= n:
        #print("action #", count + 1, ": a += b", sep = "")
        return find_operation_sequence(a + b, b, n, count + 1)
    if b < a and a <= n:
        #print("action #", count + 1, ": b += a", sep = "")
        return find_operation_sequence(a, b + a, n, count + 1)
    #print("finished.")
    return count

def minimum_operations(a, b, n):
    return find_operation_sequence(a, b, n, 0)

T = int(input())

for k in range(T):
    a, b, n = map(int, sys.stdin.readline().split())
    #print(a, b, n)
    print(minimum_operations(a, b, n))