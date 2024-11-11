ans = 0
first_b = 0
last_a = 0
same = 0

N = int(input())

for i in range(N):
    s = input()
    ans += s.count("AB")
    if s[0] == "B":
        first_b += 1
    if s[-1] == "A":
        last_a += 1
    if s[0] == "B" and s[-1] == "A":
        same +=1

ans += min(first_b, last_a)
if same > 0 and first_b ==  last_a and first_b = same:
    ans -=1
 print(ans)