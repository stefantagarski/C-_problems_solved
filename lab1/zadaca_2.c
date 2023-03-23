#include <stdio.h>

struct student {
    char name[50];
    int id;
    int num_courses;
    int courses[50];
};
typedef struct  student student;

struct course {
    char name[50];
    int code;
    int num_students;
};
typedef struct course course;

int get_most_popular_course(struct course courses[], int num_courses) {
    int max_students = -1;
    int max_course_index = -1;

    for (int i = 0; i < num_courses; i++) {
        if (courses[i].num_students > max_students) {
            max_students = courses[i].num_students;
            max_course_index = i;
        }
    }

    return max_course_index;
}

int main() {
    student students[50];
    course courses[50];
    int n = 0;
    int m = 0;
    scanf("%d %d", &n,&m);

    for (int i = 0; i < m; i++) {
        scanf("%s", courses[i].name);
        scanf("%d", &courses[i].code);
        courses[i].num_students = 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", students[i].name);
        scanf("%d", &students[i].id);
        scanf("%d", &students[i].num_courses);

        for (int j = 0; j < students[i].num_courses; j++) {
            scanf("%d", &students[i].courses[j]);

            for (int k = 0; k < m; k++) {
                if (courses[k].code == students[i].courses[j]) {
                    courses[k].num_students++;
                    break;
                }
            }
        }
    }
    int most_popular= get_most_popular_course(courses, m);
    printf("Najpopularen kurs e: %s\n", courses[most_popular].name);

    return 0;
}
