#ifndef BALLOON_H_
#define BALLOON_H_

class Balloon {
    public:
        Balloon() {}

        Balloon(int _x, int _y, int _radius) {
            x = _x;
            y = _y;
            radius = _radius;
            start = x - radius;
            finish = x + radius;
        }

        Balloon(const Balloon& that) {
            x = that.x;
            y = that.y;
            radius = that.radius;
            start = that.start;
            finish = that.finish;
        }

        Balloon& operator=(const Balloon& that) {
            if (this == &that) {
                return *this;
            }

            x = that.x;
            y = that.y;
            radius = that.radius;
            start = that.start;
            finish = that.finish;

            return *this;
        }

        int get_x() {
            return x;
        }

        int get_y() {
            return y;
        }

        int get_radius() {
            return radius;
        }

        int get_start() {
            return start;
        }

        int get_finish() {
            return finish;
        }

        bool operator < (const Balloon& that) const {
            return finish < that.finish;
        }

    private:
        int x, y, radius;
        int start, finish;
};

#endif /* BALLOON_H_ */
