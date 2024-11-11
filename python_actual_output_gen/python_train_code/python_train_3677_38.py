N = input()
if N % sum(map(int, N)):
    print("No")
else:
    print("Yes")