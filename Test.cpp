#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>


using namespace ariel;
TEST_SUITE("Point class tests") {
    Point p1(1,2);
    Point p2(3,4);
    Point p3(5,5);
    Point p4(10,7);
    Point p5(5,6);
    Point p6(0,0);

    TEST_CASE("check dist"){
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(p1.distance(p2), p2.distance(p5));
        CHECK_EQ(p2.distance(p6), 5);

    }
    TEST_CASE("MOVETWORD "){
        double dist = p1.distance(p6);
        double hlaf = dist/2;
        double third = dist / 3;
        //
        Point p7 {Point::moveTowards(p1,p6,hlaf)};
        Point p8 {Point::moveTowards(p1,p6,third)};

        CHECK_EQ(p7.distance(p1),hlaf);
        CHECK_EQ(p7.distance(p6),hlaf);
        CHECK_EQ(p8.distance(p1),doctest::Approx(third).epsilon(0.001));
        CHECK_EQ(p8.distance(p6),doctest::Approx(third * 2).epsilon(0.001));
    }
}
    TEST_SUITE("Classes initialization tests and Team modification( add(),stillAlive() )") {
         TEST_CASE("Cowboy initialization") {
        Cowboy cowboy{"Bob", Point{2, 3}};
        CHECK(cowboy.hasBoolets());
        CHECK_EQ(cowboy.getName(), "Bob");
        CHECK_EQ(cowboy.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(cowboy.getLocation().distance(Point{3, 2}), 0);

        CHECK(cowboy.isAlive());
    }

    TEST_CASE("YoungNinja initialization") {
        YoungNinja ninja{"Bob", Point{2, 3}};
        CHECK_EQ(ninja.getName(), "Bob");
        CHECK_EQ(ninja.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(ninja.getLocation().distance(Point{3, 2}), 0);

        CHECK(ninja.isAlive());
    }

    TEST_CASE("OldNinja initialization") {
        OldNinja old_ninja{"Bob", Point(2, 3)};
        CHECK_EQ(old_ninja.getName(), "Bob");
        CHECK_EQ(old_ninja.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(old_ninja.getLocation().distance(Point{3, 2}), 0);

        CHECK(old_ninja.isAlive());
    }

    TEST_CASE("TrainedNinja initialization") {
        TrainedNinja trained_ninja{"Bob", Point{2, 3}};
        CHECK_EQ(trained_ninja.getName(), "Bob");
        CHECK_EQ(trained_ninja.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(trained_ninja.getLocation().distance(Point{3, 2}), 0);

        CHECK(trained_ninja.isAlive());
    }

}

