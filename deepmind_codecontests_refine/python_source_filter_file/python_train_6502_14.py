vals = [int(x) for x in input().split()]
n = vals[0]
m = vals[1]
minPairs = 0
maxPairs = (n-m+1)*((n-m)//2)
if n%m == 0:
  peopleInGroup = n/m
  minPairs = (peopleInGroup*(peopleInGroup-1)/2)*m
else:
  peopleInGroup = n//m
  plusOneGroups = n%m
  minPairs = (peopleInGroup*(peopleInGroup-1)/2)*(m-plusOneGroups) + (peopleInGroup*(peopleInGroup+1)/2)*(plusOneGroups)
print(str(int(minPairs))+ " " +str(maxPairs))
