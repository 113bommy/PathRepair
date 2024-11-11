from operator import itemgetter


class av_let:
    def __init__(self, a, b):
        '''

        :param a: int
        :param b: int
        '''
        self.let = a
        self.cnt = b

    def __getitem__(self, item):
        return self.__getattribute__(item)


class solver:
    @staticmethod
    def solve(st, k):
        '''

        :param st: str
        :param k:  k
        :return:
        '''
        lt = set(st)
        ll = []
        for letter in lt:
            t = st.count(letter) - 1
            if t:
                ll.append(av_let(letter, t))
        ll.sort(key=itemgetter('cnt'), reverse=True)

        if len(st) < k:
            return "impossible"
        else:
            diff = k - len(lt)
            if diff <= 0:
                return 0
            else:
                answ = 0
                for lt in ll:
                    diff -= lt.cnt
                    answ += lt.cnt
                    if diff <= 0:
                        return answ+diff
                return "impossible"


print(solver.solve(input(), int(input())))