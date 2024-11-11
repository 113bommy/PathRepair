n = int(input())
list = input().split()
for i in range(0,n):
   if int(list[i]) == n:
      p = i
      break

list1 = []
list2 = []
for k in range(0,n):
   list1.append(10* int ( list[k] ) - 9)
for k in range(0,n):
   list2.append( max ( int(list1[p] ) + 1 - p + k - int( list1[k] ), n - int ( list[k] ) +1))

a = ""
b = ""

list2.sort(reverse = True)
list1.sort()
for l in range (0,n):
   a += str(list1[l])
   a += " "
   b += str(list2[l])
   b += " "

print(a)
print(b)