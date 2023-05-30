#include "TestClient.h"
#include "../../../Domain/Domain.h"
#include <cassert>

using namespace Domain;

void testClient() {
    Client client("1", "1");

    ElectricScooter scooter1("111");
    ElectricScooter scooter2("121");
    ElectricScooter scooter3("131");
    ElectricScooter scooter4("141");
    ElectricScooter scooter5("151");
    ElectricScooter scooter6("161");
    ElectricScooter scooter7("171");

    assert(!client.freeScooter(scooter1));

    assert(client.reserveScooter(scooter1));
    assert(client.reserveScooter(scooter2));
    assert(client.reserveScooter(scooter3));
    assert(client.reserveScooter(scooter4));
    assert(client.reserveScooter(scooter5));
    assert(client.reserveScooter(scooter6));
    assert(client.reserveScooter(scooter7));

    assert(!client.reserveScooter(scooter1));
    assert(!client.reserveScooter(scooter2));
    assert(!client.reserveScooter(scooter3));
    assert(!client.reserveScooter(scooter4));
    assert(!client.reserveScooter(scooter5));
    assert(!client.reserveScooter(scooter6));
    assert(!client.reserveScooter(scooter7));

    auto reservedScooters = client.getReservedScooters();
    assert(reservedScooters[0] == scooter1);
    assert(reservedScooters[1] == scooter2);
    assert(reservedScooters[2] == scooter3);
    assert(reservedScooters[3] == scooter4);
    assert(reservedScooters[4] == scooter5);
    assert(reservedScooters[5] == scooter6);
    assert(reservedScooters[6] == scooter7);

    assert(client.freeScooter(scooter1));
    assert(client.freeScooter(scooter2));
    assert(client.freeScooter(scooter3));
    assert(client.freeScooter(scooter4));
    assert(client.freeScooter(scooter5));
    assert(client.freeScooter(scooter6));

    assert(client.useScooter(scooter7));
    assert(client.isOnRide());
    assert(client.freeScooter(scooter7));
    assert(!client.freeScooter(scooter1));
    assert(!client.isOnRide());
}