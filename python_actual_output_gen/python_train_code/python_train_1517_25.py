n = int(input())
str = input()

max_id = 0

for i in range(n):
    if i+1<n and str[i]<=str[i+1]:
        max_id = i
    else:
        break

new_str = str[:max_id+1]+ str[max_id+2:]
print(new_str)