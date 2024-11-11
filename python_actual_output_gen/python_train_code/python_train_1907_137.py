N=int(input())
A=int(input())
check=N-N%500
print("Yes" if check<=A else "No")