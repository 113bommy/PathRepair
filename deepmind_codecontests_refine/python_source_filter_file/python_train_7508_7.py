from collections import Counter
n = input()
if len(Counter(n)) == 1 or len(Counter(n[:len(n)//2]+n[len(n)//2+1:])) == 1:
    print("Impossible")
    exit()
for i in range(1,len(n)):
    s1 = n[:i]
    s2 = n[i:]
    s3 = s2+s1
    if s3[len(n)//2:] == s3[:-len(n)//2] and s3 != n:
        print(1)
        exit()

print(2)


