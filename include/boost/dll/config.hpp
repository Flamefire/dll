// Copyright 2018 Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

/// \file boost/dll/config.hpp
/// \brief Imports filesystem, error_code, errc, system_error, make_error_code from Boost or C++17 into `boost::dll::fs` namespace.

#ifndef BOOST_DLL_DETAIL_CONFIG_HPP
#define BOOST_DLL_DETAIL_CONFIG_HPP

#include <boost/config.hpp>
#ifdef BOOST_HAS_PRAGMA_ONCE
#   pragma once
#endif

#ifdef BOOST_DLL_DOXYGEN
/// Define this macro to make Boost.DLL use C++17's std::filesystem::path, std::system_error and std::error_code.
#define BOOST_DLL_FORCE_ALIAS_INSTANTIATION

#endif

#ifdef BOOST_DLL_USE_STD_FS
#include <filesystem>
#include <system_error>

namespace boost { namespace dll { namespace fs {

using namespace std::filesystem;

using std::error_code;
using std::system_error;
using std::make_error_code;
using std::errc;

}}}

#else // BOOST_DLL_USE_STD_FS

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>

namespace boost { namespace dll { namespace fs {

using namespace boost::filesystem;

using boost::system::error_code;
using boost::system::system_error;
using boost::system::errc::make_error_code;
namespace errc = boost::system::errc;

}}}

#endif // BOOST_DLL_USE_STD_FS

#endif // BOOST_DLL_DETAIL_PUSH_OPTIONS_HPP
