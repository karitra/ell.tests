#include "elliptics/logger.hpp"
#include "elliptics/newapi/session.hpp"

#include <iostream>
#include <memory>

#include <cstdlib>


using namespace ioremap;

namespace ell = ioremap::elliptics;

auto main(int argc, char *argv[]) -> int {

    auto logger = elliptics::make_file_logger("boo.log", DNET_LOG_NOTICE);

    elliptics::node n(std::move(logger));

    n.add_remote(elliptics::address("localhost", 1025, 2));
    elliptics::newapi::session s(n);

    auto r =  s.lookup(elliptics::key("test1"));
    for(const auto& el : r) {
        std::cerr << "el " << r << '\n';
    }

    std::cout << "bingo!\n";

    return EXIT_SUCCESS;
}
