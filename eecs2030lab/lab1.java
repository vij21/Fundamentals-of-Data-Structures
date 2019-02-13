package eecs2030.lab1;

/**
 * A simple class for representing points in 2D Cartesian coordinates. Every
 * Point2D instance has an x and y coordinate.
 * 
 * @author EECS2030 Fall 2016
 *
 */

public class Point2 {
    private double x;
    private double y;

    public Point2() {

        x = 0;
        y = 0;
    }

    public Point2(double x2, double y2) {
        x = x2;
        y = y2;
        // TODO Auto-generated constructor stub
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public void setX(double x2) {
        x = x2;

    }

    public void setY(double y2) {
        y = y2;

    }

    public void set(double x2, double y2) {
        // TODO Auto-generated method stub
        x = x2;
        y = y2;

    }

    public java.lang.String toString() {

        String rep = "(" + x + ", " + y + ")";
        return rep;
    }

}

package eecs2030.lab1;

public class SpiroUtil {

    public static final double BIG_WHEEL_RADIUS = 1.0;

    public static double hypoX(double wheelRadius, double pencilRadius, double degrees) {
        if (wheelRadius < 0.0) {
            throw new IllegalArgumentException("wheel radius is negative");
        }
        if (wheelRadius > SpiroUtil.BIG_WHEEL_RADIUS) {
            throw new IllegalArgumentException("wheel radius is greater than SpiroUtil.BIG_WHEEL_RADIUS");
        }
        if (pencilRadius < 0.0) {
            throw new IllegalArgumentException("pencil radius is negative");
        }
        if (pencilRadius > wheelRadius) {
            throw new IllegalArgumentException("pencil radius is greater than wheel radius");
        }

        return (BIG_WHEEL_RADIUS - wheelRadius) * Math.cos(Math.toRadians(degrees))
                + pencilRadius * Math.cos(((BIG_WHEEL_RADIUS - wheelRadius) / wheelRadius) * Math.toRadians(degrees));

    }

    public static double hypoY(double wheelRadius, double pencilRadius, double degrees) {
        if (wheelRadius < 0.0) {
            throw new IllegalArgumentException("wheel radius is negative");
        }
        if (wheelRadius > SpiroUtil.BIG_WHEEL_RADIUS) {
            throw new IllegalArgumentException("wheel radius is greater than SpiroUtil.BIG_WHEEL_RADIUS");
        }
        if (pencilRadius < 0.0) {
            throw new IllegalArgumentException("pencil radius is negative");
        }
        if (pencilRadius > wheelRadius) {
            throw new IllegalArgumentException("pencil radius is greater than wheel radius");
        }

        return (BIG_WHEEL_RADIUS - wheelRadius) * Math.sin(Math.toRadians(degrees))
                - pencilRadius * Math.sin(((BIG_WHEEL_RADIUS - wheelRadius) / wheelRadius) * Math.toRadians(degrees));

    }

    public static Point2 hypo(double wheelRadius, double pencilRadius, double degrees) {
        if (wheelRadius < 0.0) {
            throw new IllegalArgumentException("wheel radius is negative");
        }
        if (wheelRadius > SpiroUtil.BIG_WHEEL_RADIUS) {
            throw new IllegalArgumentException("wheel radius is greater than SpiroUtil.BIG_WHEEL_RADIUS");
        }
        if (pencilRadius < 0.0) {
            throw new IllegalArgumentException("pencil radius is negative");
        }
        if (pencilRadius > wheelRadius) {
            throw new IllegalArgumentException("pencil radius is greater than wheel radius");
        }
        double x = (BIG_WHEEL_RADIUS - wheelRadius) * Math.cos(Math.toRadians(degrees))
                + pencilRadius * Math.cos(((BIG_WHEEL_RADIUS - wheelRadius) / wheelRadius) * Math.toRadians(degrees));
        double y = (BIG_WHEEL_RADIUS - wheelRadius) * Math.sin(Math.toRadians(degrees))
                - pencilRadius * Math.sin(((BIG_WHEEL_RADIUS - wheelRadius) / wheelRadius) * Math.toRadians(degrees));

        return new Point2(x, y);
    }

}
# Advanced-Object-Oriented-Programming
# Advanced-Object-Oriented-Programming
# Advanced-Object-Oriented-Programming
