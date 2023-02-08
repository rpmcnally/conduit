// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_relay_io_silo.hpp
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_RELAY_IO_SILO_HPP
#define CONDUIT_RELAY_IO_SILO_HPP

//-----------------------------------------------------------------------------
// external lib includes
//-----------------------------------------------------------------------------
#include <silo.h>

//-----------------------------------------------------------------------------
// conduit lib include 
//-----------------------------------------------------------------------------
#include "conduit.hpp"
#include "conduit_relay_exports.h"
#include "conduit_relay_config.h"

//-----------------------------------------------------------------------------
// -- begin conduit:: --
//-----------------------------------------------------------------------------
namespace conduit
{

//-----------------------------------------------------------------------------
// -- begin conduit::relay --
//-----------------------------------------------------------------------------
namespace relay
{

//-----------------------------------------------------------------------------
// -- begin conduit::relay::io --
//-----------------------------------------------------------------------------
namespace io
{

// Functions are provided by this include file.
#include "conduit_relay_io_silo_api.hpp"

//-----------------------------------------------------------------------------
// -- begin <>::silo --
//-----------------------------------------------------------------------------
namespace silo
{

//-----------------------------------------------------------------------------
// Write a blueprint mesh to silo
//-----------------------------------------------------------------------------
/// These methods assume `mesh` is a valid blueprint mesh.
///
/// Note: These methods use "write" semantics, they will append to existing
///       files.
///
///
//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API write_mesh(const conduit::Node &mesh,
                                  const std::string &path);

//-----------------------------------------------------------------------------
/// The following options can be passed via the opts Node:
//-----------------------------------------------------------------------------
/// opts:
///      TODO
///
//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API write_mesh(const conduit::Node &mesh,
                                  const std::string &path,
                                  const conduit::Node &opts);

//-----------------------------------------------------------------------------
// Save a blueprint mesh to silo
//-----------------------------------------------------------------------------
/// These methods assume `mesh` is a valid blueprint mesh.
///
/// Note: These methods use "save" semantics, they will overwrite existing
///       files.
///
///
//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save_mesh(const conduit::Node &mesh,
                                 const std::string &path);

//-----------------------------------------------------------------------------
/// The following options can be passed via the opts Node:
//-----------------------------------------------------------------------------
/// opts:
///      TODO
///
//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save_mesh(const conduit::Node &mesh,
                                 const std::string &path,
                                 const conduit::Node &opts);

}
//-----------------------------------------------------------------------------
// -- end <>::silo --
//-----------------------------------------------------------------------------

}
//-----------------------------------------------------------------------------
// -- end conduit::relay::io --
//-----------------------------------------------------------------------------


}
//-----------------------------------------------------------------------------
// -- end conduit::relay --
//-----------------------------------------------------------------------------


}
//-----------------------------------------------------------------------------
// -- end conduit:: --
//-----------------------------------------------------------------------------


#endif

