N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
a_b = b_a = 0
for a, b in zip(A, B):
    a_b += max(0, a-b) + max(0, (b-a)%2)
    b_a += max(0, (b-a)//2)
t = max(a_b, b_a)
#print(t)
if sum(B)-sum(A) >= t:
    print("Yes")
else:
    print("No")
