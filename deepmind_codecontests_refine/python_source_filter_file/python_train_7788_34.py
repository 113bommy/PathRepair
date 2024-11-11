n = int(input())
alist  = list(map(int,input().split()))
list1 = alist[1::2]
list2 = alist[0::2]
from collections import Counter
dic1 = Counter(list1).most_common()
dic2 = Counter(list2).most_common()
dic1.append([0,0])
dic2.append([0,])
if dic1[0][0]!=dic2[0][0]:
  print(n - dic1[0][1] - dic2[0][1])
else:
  print(min(n - dic1[0][1] - dic2[1][1], n -dic1[1][1] - dic2[0][1]))