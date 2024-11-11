s=input()
aa=int(s[:2])
bb=int(s[3:])
if 0<aa<=12 and 0<bb<=12: ans='AMBIGUOUS'
elif 0<bb<=12: ans='YYMM'
elif 0<aa<=12: ans='MMYY'
else: ans='NA'
print(ans)