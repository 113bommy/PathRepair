# greedy alg
n,k,x=map(int,input().split())
arr=[int(x) for x in input().split()]

print(sum(arr[:-1*k])+k*x)
