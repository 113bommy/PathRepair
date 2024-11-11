n = eval(input())
line = input()
strings = line.split()
list = []

for string in strings:
    list.append(eval(string))
    
result = sorted(list)
count = 0
for i in range(len(result)-1):
  if result[i + 1] != result[i]+1:
    count+=(result[i+1] - result[i])//2

print(count)