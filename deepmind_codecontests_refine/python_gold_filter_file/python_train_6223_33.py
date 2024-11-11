s=input()
t=input()
mx_match=0
for i in range(len(s)-len(t)+1):
  mx_match=max(mx_match,sum(s[i+j]==t[j] for j in range(len(t))))
print(len(t)-mx_match)