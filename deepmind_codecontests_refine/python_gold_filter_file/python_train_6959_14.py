n = int(input())
for i in reversed(range(int(n**0.5)+1)):
    if n%i==0:
        print(max(len(str(i)), len(str(n//i))))
        exit()
