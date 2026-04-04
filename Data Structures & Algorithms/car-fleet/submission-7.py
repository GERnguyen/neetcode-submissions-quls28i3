class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(p, s) for p, s in zip(position, speed)]
        cars.sort(reverse=True)

        aheadCarTime = (target - cars[0][0]) / cars[0][1]
        fleets = len(cars)
        for i in range(1, len(cars)):
            curCarTime = (target - cars[i][0]) / cars[i][1]
            if curCarTime <= aheadCarTime: 
                fleets-=1
                curCarTime = aheadCarTime
            aheadCarTime = curCarTime

        return fleets

        