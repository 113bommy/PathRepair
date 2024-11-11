s = input()
answer = 0
for q in s:
    answer+=(int(q) % 4 == 0)
for i in range(1,len(s)):
    answer+= (int(s[i-1:i+1:1]) % 4 == 0) * i
print(answer)