class Guest(object):
    def __init__(self, gender, start_day, end_day):
        self.gender = gender
        self.start_day = start_day
        self.end_day = end_day

    def __str__(self):
        return " ".join([self.gender, str(self.start_day), str(self.end_day)])


class Party(object):
    def __init__(self, number_of_guests):
        self.number_of_guests = number_of_guests
        self.guests = []
        self.number_of_available_guests_on_day = [0]*366

    def __str__(self):
        output = ""
        for counter in range(self.number_of_guests):
            output = "\n".join([output, self.guests[counter].__str__()])
        return output

    def add_guest(self, gender, start_day, end_day):
        self.guests.append(Guest(gender, start_day, end_day))

    def determine_guests_available_on_day(self,index):
        day = index + 1
        males = 0
        females = 0
        for guest in self.guests:
            if guest.start_day <= day <= guest.end_day:
                if guest.gender == 'M':
                    males += 1
                else:
                    females += 1
        self.number_of_available_guests_on_day[index] = min(males,females)*2

    def check_all_days(self):
        for index in range(366):
            self.determine_guests_available_on_day(index)

if __name__ == '__main__':
    doors_party = Party(int(input()))
    for i in range(doors_party.number_of_guests):
        input_guest = input().split(" ")
        doors_party.add_guest(input_guest[0],
                              int(input_guest[1]),
                              int(input_guest[2]))

    print(doors_party)

    doors_party.check_all_days()

    print(max(doors_party.number_of_available_guests_on_day))
