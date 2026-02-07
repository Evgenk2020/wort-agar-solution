#include "../include/output.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <print>
#include <format>
#include <filesystem>

void help_info::see_info()
{
    std::println(
        "*** Визначення об'єму компонентів суслового агару з натуральної сировини ***\n"
        "\n"
        "Для виводу в термінал:\n"
        "d [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]\n"
        "\n"
        "Для виводу у файл:\n"
        "-df [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]\n"
        "\n"
        "Для довідки:\n"
        "-h | --help\n"
        "\n"
        "Додаткова інформація:\n"
        "-i");
}

void inf_indo::see_info()
{
    std::println(
        "В лабораторних умовах приготування розчину заданої\n"
        "масової чатки розчиненої речовини з розчинів\n"
        "з відомою масовою часткою здійснюється відповідно правилу хреста:\n"
        "m1 * W1 + m2 * W2 = W3 * (m1 + m2)\n"
        "\n"
        "Утиліта визначає дані:\n"
        "- об'єм води для розведення концентрованого розчину\n"
        "- об'єм розведеного розчину\n"
        "виходячи з концентрації початкового розчину, об'єму фільтрата\n"
        "і концентрації розчину, який готується");
}

//--------------------------------------------------

void screen_info::see_info(wort_solution *wrt)
{
    std::print("Концентрація нерозведеного розчина: {}%\n", wrt->first_wort);
    std::print("Концентрація розведеного розчина: {}%\n", wrt->finish_wort);
    std::print("Об'єм фільтрата: {} мл\n", wrt->vol_filtrate);
    std::print("Об'єм води для розчинення: {:.2f} мл\n", sol.solutions(sol.water_for_solvation)->get_solvation(*wrt));
    std::print("Об'єм розчиненого середовища: {:.2f} мл\n", sol.solutions(sol.total_volume)->get_solvation(*wrt));
}

void file_info::see_info(wort_solution *wrt)
{
    namespace file_system = std::filesystem;
    const file_system::path file{"wort-dada.csv"};
    std::ofstream csv(file, std::ios::app);

    auto loc = std::locale{"uk_UA.utf8"};
    constexpr std::string_view formatter = "\"{}\",\"{:.2Lf}\"\n";

    csv << std::format(loc, formatter, "Концентрація нерозведеного розчина (%):", wrt->first_wort);
    csv << std::format(loc, formatter, "Концентрація розведеного розчина (%):", wrt->finish_wort);
    csv << std::format(loc, formatter, "Об'єм фільтрата (мл):", wrt->vol_filtrate);
    csv << std::format(loc, formatter, "Об'єм води для розчинення (мл):", sol.solutions(sol.water_for_solvation)->get_solvation(*wrt));
    csv << std::format(loc, formatter, "Об'єм розчиненого середовища (мл):", sol.solutions(sol.total_volume)->get_solvation(*wrt));
    csv << std::endl;
    
    std::print("Дані додані у файл wort-dada.csv\n");
}

//--------------------------------------------------

print_info::print_info(general_info *temp) : g_info(temp) {}
print_info::print_info(data_info *temp) : d_info(temp) {}

void print_info::_print() { g_info->see_info(); }
void print_info::_print(wort_solution temp) { d_info->see_info(&temp); }

print_info::~print_info()
{
    delete g_info;
    g_info = nullptr;

    delete d_info;
    d_info = nullptr;
}
