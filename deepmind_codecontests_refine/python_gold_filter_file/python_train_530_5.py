t = int(input())

def count(x1, y1, x2, y2):
    n = y2-y1+1
    m = x2-x1+1
    W = ((n+1)//2)*((m+1)//2)+(n-(n+1)//2)*(m-(m+1)//2)
    B = ((n+1)//2)*(m//2)+(n-(n+1)//2)*(m-m//2)
    if (x1+y1)%2 == 1:
        W, B = B, W
    return W, B

for _ in range(t):
    n, m = map(int, input().split())
    W = ((n+1)//2)*((m+1)//2)+(n-(n+1)//2)*(m-(m+1)//2)
    B = ((n+1)//2)*(m//2)+(n-(n+1)//2)*(m-m//2)
    #print(W, B)
    x1, y1, x2, y2 = map(int, input().split())
    x3, y3, x4, y4 = map(int, input().split())
    if x2 < x3:
        w1, b1 = count(x1, y1, x2, y2)
        W += -w1+w1+b1
        B -= b1
        w2, b2 = count(x3, y3, x4, y4)
        W -= w2
        B += w2+b2-b2
    elif x3 <= x2 <= x4:
        if x1 < x3:
            if y2 < y3:
                w1, b1 = count(x1, y1, x2, y2)
                W += -w1+w1+b1
                B -= b1
                w2, b2 = count(x3, y3, x4, y4)
                W -= w2
                B += w2+b2-b2
            elif y3 <= y2 <= y4:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y3, x2, y2)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y1, x2, y2)
                    #print(w1, b1, w1_, b1_)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    #print(W, B)
                    w2, b2 = count(x3, y3, x4, y4)
                    #print(w2, b2)
                    W -= w2
                    B += w2+b2-b2
            else:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y3, x2, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y1, x2, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                else:
                    w1, b1 = count(x1, y1, x2, y2)
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
        elif x3 <= x1 <= x4:
            if y2 < y3:
                w1, b1 = count(x1, y1, x2, y2)
                W += -w1+w1+b1
                B -= b1
                w2, b2 = count(x3, y3, x4, y4)
                W -= w2
                B += w2+b2-b2
            elif y3 <= y2 <= y4:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y3, x2, y2)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
            else:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y3, x2, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y1, x2, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                else:
                    w1, b1 = count(x1, y1, x2, y2)
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
    elif x4 < x2:
        if x1 < x3:
            if y2 < y3:
                w1, b1 = count(x1, y1, x2, y2)
                W += -w1+w1+b1
                B -= b1
                w2, b2 = count(x3, y3, x4, y4)
                W -= w2
                B += w2+b2-b2
            elif y3 <= y2 <= y4:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y3, x4, y2)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y1, x4, y2)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
            else:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y3, x4, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x3, y1, x4, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                else:
                    w1, b1 = count(x1, y1, x2, y2)
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
        elif x3 <= x1 <= x4:
            if y2 < y3:
                w1, b1 = count(x1, y1, x2, y2)
                W += -w1+w1+b1
                B -= b1
                w2, b2 = count(x3, y3, x4, y4)
                W -= w2
                B += w2+b2-b2
            elif y3 <= y2 <= y4:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y3, x4, y2)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y1, x4, y2)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
            else:
                if y1 < y3:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y3, x4, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                elif y3 <= y1 <= y4:
                    w1, b1 = count(x1, y1, x2, y2)
                    w1_, b1_ = count(x1, y1, x4, y4)
                    w1 -= w1_
                    b1 -= b1_
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
                else:
                    w1, b1 = count(x1, y1, x2, y2)
                    W += -w1+w1+b1
                    B -= b1
                    w2, b2 = count(x3, y3, x4, y4)
                    W -= w2
                    B += w2+b2-b2
        else:
            w1, b1 = count(x1, y1, x2, y2)
            W += -w1+w1+b1
            B -= b1
            w2, b2 = count(x3, y3, x4, y4)
            W -= w2
            B += w2+b2-b2
    print(W, B)
