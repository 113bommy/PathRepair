import math;

def calLength(p1, p2):
    l = math.pow(p1[0] - p2[0], 2) + math.pow(p1[1] - p2[1], 2);
    return math.sqrt(l);

def main():
    getS = input();
    getS = getS.split();
    a = int(getS[0]);
    b = int(getS[1]);
    n = int(input());
    v = [a, b];

    taxi = [];
    for i in range(0, n):
        ta = [];
        getS = input();
        getS = getS.split();
        ta.append(int(getS[0]));
        ta.append(int(getS[1]));
        ta.append(int(getS[2]));
        taxi.append(ta);

    re = False;
    for i in range(0, len(taxi)):
        t = calLength(v, taxi[i]) / taxi[i][2];
        #print (calLength(v, taxi[i]) / taxi[i][2]);
        if t == 0:
            #print (0);
            return;
        if (re == False) or (re != False and re > t):
            re = t;

    print (float(re));

main();