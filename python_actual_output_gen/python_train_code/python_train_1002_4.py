months=['Januray', 'February', 'March', 'April', 'May', 'June', 'July',
        'August', 'September', 'October', 'November', 'December']
mth=input()
i=months.index(mth)
k=int(input())
t=i+k
if t>12:
    t=t%12
print(months[t])
