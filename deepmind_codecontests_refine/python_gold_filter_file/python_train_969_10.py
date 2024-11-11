n = int(input())
list1 = list(map(int,input().split()))
num = 0
if len(list1) > 1:
                for i in range(1,n):
                                if list1[i] > max(list1[:i]) or list1[i] < min(list1[:i]):
                                                num += 1
                print(num)
else:
                print('0')

                                
