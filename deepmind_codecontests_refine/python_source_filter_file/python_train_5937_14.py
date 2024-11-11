#coding: UTF-8
import statistics as st

while True:
    N = int(input())
    if N = 0:
        break
    buf = list(map(float, input().split()))
    sd = st.pstdev(buf)
    print("%.8f"%sd)

