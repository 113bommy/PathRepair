''' sau khi đọc đề hiểu vấn đề như sau: 
1. Valera anh ta muốn đeo 4 màu khác nhau đi dự tiệc
2. Yêu cầu: anh ta có n móng ngựa n màu, anh ta 
cần mua thêm bao nhiêu để có 4 màu 
'''
data = input().split()
s = ''
for i in data:
    if i not in s:
        s += str(i)
canmua = 4 - len(s)
#print(s)
if canmua == 0:
    print(0)
else:
    print(canmua)
