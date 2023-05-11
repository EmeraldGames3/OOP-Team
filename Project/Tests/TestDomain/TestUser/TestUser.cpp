#include "TestUser.h"
#include <cassert>
#include "../../../Domain/Domain.h"

void testUser(){
    // Create a new user with username "john" and password "12345"
    User user("john", "12345");

    // Test the getters
    assert(user.getUsername() == "john");
    assert(user.getPassword() == "12345");

    // Test the setters
    user.setUsername("new_username");
    assert(user.getUsername() == "new_username");

    user.setPassword("new_password");
    assert(user.getPassword() == "new_password");

    // Test empty username and password
    user.setUsername("");
    assert(user.getUsername().empty());

    user.setPassword("");
    assert(user.getPassword().empty());

    // Test long username and password
    user.setUsername("this_is_a_very_long_username_that_exceeds_the_maximum_allowed_length");
    assert(user.getUsername() == "this_is_a_very_long_username_that_exceeds_the_maximum_allowed_length");

    user.setPassword("this_is_a_very_long_password_that_exceeds_the_maximum_allowed_length");
    assert(user.getPassword() == "this_is_a_very_long_password_that_exceeds_the_maximum_allowed_length");
}