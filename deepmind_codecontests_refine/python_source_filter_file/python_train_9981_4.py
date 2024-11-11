from datetime import datetime
def era(f):
    meiji_st  = datetime(1868, 9, 8)
    taisho_st = datetime(1912, 7,30)
    showa_st  = datetime(1926,12,25)
    heisei_st = datetime(1989, 1, 8)

    y,m,d = f
    dt = datetime(y,m,d)
    if dt > heisei_st:
        ret = "heisei %d %d %d" % (dt.year - heisei_st.year+1,dt.month,dt.day) 
    elif dt > showa_st:
        ret = "showa %d %d %d" % (dt.year - showa_st.year+1,dt.month,dt.day) 
    elif dt > taisho_st:
        ret = "taisho %d %d %d" % (dt.year - taisho_st.year+1,dt.month,dt.day) 
    elif dt > meiji_st:
        ret = "meiji %d %d %d" % (dt.year - meiji_st.year+1,dt.month,dt.day) 
    else:
       ret = "pre-meiji"

    return(ret)

while True:
    try:
        f = map(int, input().strip().split())
        print(era(f))
    except EOFError:
        break