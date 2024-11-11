from sys import stdin, stdout
input = stdin.readline
 
kik = input()[:-1]
nancy = len(kik)
arr = [0] * nancy
 
for i in range(1, nancy):
         if kik[i - 1] == kik[i]:
                  arr[i] = arr[i - 1] + 1
         else:
                  arr[i] = arr[i - 1]
 
for i in range(int(input())):
         j, k = map(int, input().split())
         stdout.write(str(arr[k - 1] - arr[j - 1]))
         stdout.write("\nancy")