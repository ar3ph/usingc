// vibed
#include <glib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Student;

// Helper function to create a student
Student* student_create(const char *name, int age) {
    Student *s = g_malloc(sizeof(Student));
    s->name = g_strdup(name);
    s->age = age;
    return s;
}

// Helper function to free a student
void student_free(Student *s) {
    if (s) {
        g_free(s->name);
        g_free(s);
    }
}

// Test: Create a student with valid data
static void test_student_creation(void) {
    Student *s = student_create("Alice", 20);
    
    g_assert_nonnull(s);
    g_assert_nonnull(s->name);
    g_assert_cmpstr(s->name, ==, "Alice");
    g_assert_cmpint(s->age, ==, 20);
    
    student_free(s);
}

// Test: Create a student with empty name
static void test_student_empty_name(void) {
    Student *s = student_create("", 25);
    
    g_assert_nonnull(s);
    g_assert_nonnull(s->name);
    g_assert_cmpstr(s->name, ==, "");
    g_assert_cmpint(s->age, ==, 25);
    
    student_free(s);
}

// Test: Create a student with zero age
static void test_student_zero_age(void) {
    Student *s = student_create("Bob", 0);
    
    g_assert_nonnull(s);
    g_assert_cmpstr(s->name, ==, "Bob");
    g_assert_cmpint(s->age, ==, 0);
    
    student_free(s);
}

// Test: Create a student with negative age
static void test_student_negative_age(void) {
    Student *s = student_create("Charlie", -5);
    
    g_assert_nonnull(s);
    g_assert_cmpstr(s->name, ==, "Charlie");
    g_assert_cmpint(s->age, ==, -5);
    
    student_free(s);
}

// Test: Create a student with long name
static void test_student_long_name(void) {
    const char *long_name = "ThisIsAVeryLongNameForTestingPurposesWithMoreThanFiftyCharacters";
    Student *s = student_create(long_name, 30);
    
    g_assert_nonnull(s);
    g_assert_cmpstr(s->name, ==, long_name);
    g_assert_cmpint(s->age, ==, 30);
    
    student_free(s);
}

// Test: Modify student data
static void test_student_modification(void) {
    Student *s = student_create("David", 22);
    
    g_free(s->name);
    s->name = g_strdup("David Smith");
    s->age = 23;
    
    g_assert_cmpstr(s->name, ==, "David Smith");
    g_assert_cmpint(s->age, ==, 23);
    
    student_free(s);
}

// Test: Multiple students don't interfere
static void test_multiple_students(void) {
    Student *s1 = student_create("Eve", 19);
    Student *s2 = student_create("Frank", 21);
    
    g_assert_cmpstr(s1->name, ==, "Eve");
    g_assert_cmpint(s1->age, ==, 19);
    g_assert_cmpstr(s2->name, ==, "Frank");
    g_assert_cmpint(s2->age, ==, 21);
    
    student_free(s1);
    student_free(s2);
}

int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);
    
    // Register tests
    g_test_add_func("/student/creation", test_student_creation);
    g_test_add_func("/student/empty_name", test_student_empty_name);
    g_test_add_func("/student/zero_age", test_student_zero_age);
    g_test_add_func("/student/negative_age", test_student_negative_age);
    g_test_add_func("/student/long_name", test_student_long_name);
    g_test_add_func("/student/modification", test_student_modification);
    g_test_add_func("/student/multiple_students", test_multiple_students);
    
    return g_test_run();
}