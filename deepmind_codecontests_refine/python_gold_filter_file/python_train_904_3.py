n = int(input())

arr = []

for i in range(0, n):
  arr.append((int(input()), i+1))

sorted_arr = sorted(arr, key=lambda x: x[0])

Checker = dict()

for i in sorted_arr:
  Checker[i[0]] = 0

for i in sorted_arr:
  Checker[i[0]] = Checker[i[0]] + 1
if(len(Checker) == 1):
  print("Exemplary pages.")
elif(len(sorted_arr) == 2):
  if(abs(sorted_arr[0][0] - sorted_arr[1][0])%2 == 0):
    print(str(int(abs(sorted_arr[0][0] - sorted_arr[1][0])/2)) + " ml. from cup #" + str(sorted_arr[0][1]) + " to cup #" + str(sorted_arr[n-1][1]) +".")
  else:
    print("Unrecoverable configuration.")
elif (len(sorted_arr) == 3) :
  a = sorted_arr[0][0] + sorted_arr[1][0] + sorted_arr[2][0]
  if (a%3 != 0):
    print("Unrecoverable configuration.")
  else:
    print(str(int(a/3)) + " ml. from cup #" + str(sorted_arr[0][1]) + " to cup #" + str(sorted_arr[n-1][1]) + ".")

elif(len(Checker) == 3):
  run_sum = sum([a[0] for a in sorted_arr])

  if (run_sum % n != 0):
    print("Unrecoverable configuration.")
  else:
    print(str(sorted_arr[n-1][0] - int(run_sum/n)) + " ml. from cup #" + str(sorted_arr[0][1]) + " to cup #" + str(sorted_arr[n-1][1]) + ".")

else:
  print("Unrecoverable configuration.")
